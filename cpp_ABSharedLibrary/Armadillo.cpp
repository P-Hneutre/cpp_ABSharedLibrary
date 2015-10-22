#include "Armadillo.hh"

Armadillo::Armadillo()
{
}

Armadillo::~Armadillo()
{
}

void Armadillo::scream() const
{
	std::cout << "I'm Armadillo" << std::endl;
}

extern "C"
{
	IAnimal* load_plugin()
	{
		return new Armadillo();
	}
}