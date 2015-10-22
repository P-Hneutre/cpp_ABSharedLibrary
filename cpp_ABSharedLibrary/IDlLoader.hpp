#pragma once

#include <iostream>

template <typename T>
class IDlLoader
{
	public:
		virtual ~IDlLoader() {};

	public:
		virtual void	open() = 0;
		virtual void	close() const = 0;
		virtual T*		getInstance() const = 0;
};