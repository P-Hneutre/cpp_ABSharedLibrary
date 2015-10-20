#pragma once

#include <iostream>
#include "IAnimal.hh"

class Platypus : public IAnimal 
{
	public:
		Platypus();
		~Platypus();

	public:
		void	scream();
};