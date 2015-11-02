#pragma once

#include <sys/types.h>
#include <dirent.h>
#include <map>
#include "IDlManager.hpp"

template <typename T>
class UDlManager : public IDlManager<T>
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
UDlManager<T>::UDlManager()
{

}

template<typename T>
UDlManager<T>::~UDlManager()
{

}

template<typename T>
void UDlManager<T>::load(std::string const & name)
{
	std::cout << "lib = " << DIR_NAME + name + ".so" << std::endl;
	_loaders.insert(std::make_pair(name, new UDlLoader<T>(DIR_NAME + name + ".so")));
	_loaders.find(name)->second->open();
	std::cout << "name _loaders = " << _loaders.find(name)->first << std::endl;
	_plugins.insert(std::make_pair(name, _loaders.find(name)->second->getInstance()));
	std::cout << "name _ plugins = " << _plugins.find(name)->first << std::endl;
}

template<typename T>
void UDlManager<T>::loadAll(std::string const & dirName)
{
	DIR *dp;
	struct dirent *dirp;

	if ((dp = opendir(dirName.c_str())) == NULL)
		throw std::runtime_error("Error : opendir " + dirName);

	while ((dirp = readdir(dp)) != NULL) {
		std::string s(dirp->d_name);
		std::size_t found = s.find(".so");
		if (found != std::string::npos)
		{
			std::cout << s << std::endl;
			std::string libName = s.substr(0, s.size() - 3);
			std::cout << libName << std::endl;
			this->load(libName);
		}
	}
	closedir(dp);
}

template<typename T>
T * UDlManager<T>::getObject(std::string const & name) const
{
	return _plugins.find(name)->second;
}
