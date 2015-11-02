#pragma once

#include <iostream>
#include <stdexcept>
#include <Windows.h>
#include "IDlLoader.hpp"

template <typename T>
class WDlLoader : public IDlLoader<T>
{
public:
	WDlLoader(const char *filename);
	WDlLoader(std::string const & filename);
	WDlLoader(const WDlLoader &old);
	WDlLoader<T> &operator=(const WDlLoader<T> &old);
	virtual ~WDlLoader();

public:
	void			open();
	void			close() const;
	T*				getInstance() const;

private:
	std::string		_filename;
	HMODULE			_handle;
};

template <typename T>
WDlLoader<T>::WDlLoader(const char *filename)
{
	_filename = std::string(filename);
	_handle = NULL;
}

template<typename T>
WDlLoader<T>::WDlLoader(std::string const & filename)
{
	_filename = filename;
	_handle = NULL;
}

template <typename T>
WDlLoader<T>::WDlLoader(const WDlLoader &old)
{
	_filename = old._filename;
	_handle = old._handle;
}

template<typename T>
WDlLoader<T>& WDlLoader<T>::operator=(const WDlLoader<T>& old)
{
	_filename = old._filename;
	_handle = old._handle;
	return *this;
}

template <typename T>
WDlLoader<T>::~WDlLoader()
{
}

template<typename T>
void WDlLoader<T>::open()
{
	_handle = LoadLibraryA(_filename.c_str());
	if (_handle == NULL)
		throw std::runtime_error("Error : dlopen " + _filename);
}

template<typename T>
void WDlLoader<T>::close() const
{
	if (!FreeLibrary(_handle))
		throw std::runtime_error("Error : dlclose " + _filename);
}

template<typename T>
T * WDlLoader<T>::getInstance() const
{
	typedef T* (*EXTERNAL_CREATOR)();
	EXTERNAL_CREATOR external_creator;

	external_creator = (EXTERNAL_CREATOR)GetProcAddress(_handle, "getDLLInterface");
	if (external_creator == NULL)
	{
		FreeLibrary(_handle);
		throw std::runtime_error("Error : dlsym ");
	}
	return external_creator();
}

