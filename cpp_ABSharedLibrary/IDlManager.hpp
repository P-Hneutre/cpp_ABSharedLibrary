#pragma once

#include <iostream>
#include <string>

#define DIR_NAME "../plugins/"

template <typename T>
class IDlManager
{
	public:
		virtual ~IDlManager() {};

	public:
		virtual void	load(std::string const &name) = 0;
		virtual void	loadAll(std::string const &dirName) = 0;
		virtual T*		getObject(std::string const &name) const = 0;
};