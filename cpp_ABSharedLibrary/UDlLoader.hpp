#pragma once

#include <stdexcept>
#include <dlfcn.h>
#include "IDlLoader.hpp"

template <typename T>
class UDlLoader : public IDlLoader<T>
{
	public:
		UDlLoader(const char *filename);
		UDlLoader(std::string const & filename);
		UDlLoader(const UDlLoader &old);
		UDlLoader<T> &operator=(const UDlLoader<T> &old);
		virtual ~UDlLoader();

	public:
		void			open();
		void			close() const;
		T*				getInstance() const;

	private:
		std::string		_filename;
		void			*_handle;
};

template <typename T>
UDlLoader<T>::UDlLoader(const char *filename)
{
	_filename = std::string(filename);
	_handle = NULL;
}

template<typename T>
UDlLoader<T>::UDlLoader(std::string const & filename)
{
	_filename = filename;
	_handle = NULL;
}

template <typename T>
UDlLoader<T>::UDlLoader(const UDlLoader &old)
{
	_filename = old._filename;
	_handle = old._handle;
}

template<typename T>
UDlLoader<T>& UDlLoader<T>::operator=(const UDlLoader<T>& old)
{
	_filename = old._filename;
	_handle = old._handle;
	return *this;
}

template <typename T>
UDlLoader<T>::~UDlLoader()
{
}

template<typename T>
void UDlLoader<T>::open()
{
	_handle = dlopen(_filename.c_str(), RTLD_LAZY);
	if (_handle == NULL)
		throw std::runtime_error("Error : dlopen " + _filename);
}

template<typename T>
void UDlLoader<T>::close() const
{
	if (dlclose(_handle) != 0)
		throw std::runtime_error("Error : dlclose " + _filename);
}

template<typename T>
T * UDlLoader<T>::getInstance() const
{
	T* (*external_creator)();

	external_creator = reinterpret_cast<T* (*)()>(dlsym(_handle, "getDLLInterface"));
	if (external_creator == NULL)
		throw std::runtime_error("Error : dlsym ");
	return external_creator();
}

