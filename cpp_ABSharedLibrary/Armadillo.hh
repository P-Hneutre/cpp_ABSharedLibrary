#pragma once
#include "IAnimal.hh"
class Armadillo : public IAnimal {
public:
	virtual ~Armadillo();
	virtual void	scream();
};