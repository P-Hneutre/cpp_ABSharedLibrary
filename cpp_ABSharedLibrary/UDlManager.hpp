#pragma once

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
	_loaders.insert(std::make_pair(name, new UDlManager<T>(DIR + name + ".so")));
	_loaders.find(name)->second->open();
	std::cout << "name _loaders = " << _loaders.find(name)->second << std::endl;
	_plugins.insert(std::make_pair(name, _loaders.find(name)->second->getInstance()));
	std::cout << "name _ plugins = " << _plugins.find(name)->second << std::endl;
}

template<typename T>
void UDlManager::loadAll(std::string const & dirName)
{
}

template<typename T>
T * UDlManager::getObject(std::string const & name) const
{
	return _plugins.find(name)->second;
}
