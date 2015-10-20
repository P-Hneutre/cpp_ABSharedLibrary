#pragma once

#include "IAnimal.hh"

class Platypus : public IAnimal 
{
	public:
		virtual			~Platypus();
		virtual	void	scream();
};