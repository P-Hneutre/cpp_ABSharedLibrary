#pragma once

#include <iostream>
#include "IAnimal.hh"

class Armadillo : public IAnimal 
{
	public:
		Armadillo();
		virtual ~Armadillo();

	public:
		virtual void	scream() const;
};