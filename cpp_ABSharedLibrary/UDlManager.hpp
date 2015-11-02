#pragma once

#include <sys/types.h>
#include <dirent.h>
#include "IDlManager.hpp"

template <typename T>
class UDlManager : public IDlManager
{
	public:
		UDlManager();
		virtual ~UDlManager();

	public:
		void	load(std::string const &name);
		void	loadAll(std::string const &dirName);
		T*		getObject(std::string const &name) const;

	private:
		std::map<std::string, IDlLoader<T>*>	_loaders;
		std::map<std::string, T*>				_plugins;
};

template<typename T>
UDlManager::UDlManager()
{

}

template<typename T>
UDlManager::~UDlManager()
{

}

template<typename T>
void UDlManager::load(std::string const & name)
{
	std::cout << "lib = " << DIR + name + ".so" << std::endl;
	_loaders.insert(std::make_pair(name, new WDlLoader<T>(DIR + name + ".so")));
	_loaders.find(name)->second->open();
	std::cout << "name _loaders = " << _loaders.find(name)->first << std::endl;
	_plugins.insert(std::make_pair(name, _loaders.find(name)->second->getInstance()));
	std::cout << "name _ plugins = " << _plugins.find(name)->first << std::endl;
}

template<typename T>
void UDlManager::loadAll(std::string const & dirName)
{
	DIR *dp;
	struct dirent *dirp;

	if ((dp = opendir(dir.c_str())) == NULL)
		throw std::runtime_error("Error : opendir " + dirName);

	while ((dirp = readdir(dp)) != NULL) {
		std::string s(dirp->d_name);
		std::size_t found = arr_s.find(".so");
		if (found != std::string::npos)
		{
			std::cout << arr_s << std::endl;
			std::string libName = arr_s.substr(0, std::size(arr_s) - 3);
			std::cout << libName << std::endl;
			this->load(libName);
		}
	}
	closedir(dp);
}

template<typename T>
T * UDlManager::getObject(std::string const & name) const
{
	return _plugins.find(name)->second;
}
