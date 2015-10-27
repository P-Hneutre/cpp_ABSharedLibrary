#pragma once

#ifdef _WIN32
	#define MODULE_API __declspec(dllexport)
#else
	#define MODULE_API
#endif

class IAnimal
{
	public:
		virtual	~IAnimal() {};

	public:
		virtual void	scream() const = 0;
};

