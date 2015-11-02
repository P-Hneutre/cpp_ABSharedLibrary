#pragma once

#include <stdexcept>
#include <windows.h>
#include <tchar.h> 
#include <stdio.h>
#include <strsafe.h>
#include <map>
#include "IDlManager.hpp"

template<typename T>
class WDlManager : public IDlManager<T>
{
	public:
		WDlManager();
		virtual ~WDlManager();

	public:
		void	load(std::string const &name);
		void	loadAll(std::string const &dirName);
		T*		getObject(std::string const &name) const;

	private:
		std::map<std::string, IDlLoader<T>*>	_loaders;
		std::map<std::string, T*>				_plugins;
};

template<typename T>
WDlManager<T>::WDlManager()
{

}

template<typename T>
WDlManager<T>::~WDlManager()
{
	/*std::map<std::string, IDlLoader<T>*>::iterator it = _loaders.begin();

	while (it != _loaders.end()) {
		std::cout << "ok";
		it->second->close();
	}*/
}

template<typename T>
void WDlManager<T>::load(std::string const & name)
{
	std::cout << "lib = " << DIR_NAME + name + ".dll" << std::endl;
	_loaders.insert(std::make_pair(name, new WDlLoader<T>(DIR_NAME + name + ".dll")));
	_loaders.find(name)->second->open();
	std::cout << "name _loaders = " << _loaders.find(name)->first << std::endl;
	_plugins.insert(std::make_pair(name, _loaders.find(name)->second->getInstance()));
	std::cout << "name _ plugins = " << _plugins.find(name)->first << std::endl;
}

std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

template<typename T>
void WDlManager<T>::loadAll(std::string const & dirName)
{
	WIN32_FIND_DATA ffd;
	TCHAR szDir[MAX_PATH];
	HANDLE hFind = INVALID_HANDLE_VALUE;
	size_t length_of_arg;
	std::wstring stemp = s2ws(dirName);
	LPCWSTR result = stemp.c_str();

	StringCchLength(result, MAX_PATH, &length_of_arg);
	if (length_of_arg > (MAX_PATH - 3))
		throw std::runtime_error("Directory path is too long");

	StringCchCopy(szDir, MAX_PATH, result);
	StringCchCat(szDir, MAX_PATH, TEXT("\\*"));

	hFind = FindFirstFile(szDir, &ffd);
	if (hFind == INVALID_HANDLE_VALUE)
		throw std::runtime_error("Find firt file");
	do
	{
		if (!(ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
		{
			std::wstring arr_w(ffd.cFileName);
			std::string arr_s(arr_w.begin(), arr_w.end());
			std::size_t found = arr_s.find(".dll");
			if (found != std::string::npos)
			{
				std::cout << arr_s << std::endl;
				std::string libName = arr_s.substr(0, std::size(arr_s) - 4);
				std::cout << libName << std::endl;
				this->load(libName);
			}
		}
	} while (FindNextFile(hFind, &ffd) != 0);

	FindClose(hFind);
}

template<typename T>
T * WDlManager<T>::getObject(std::string const & name) const
{
	return _plugins.find(name)->second;
}
