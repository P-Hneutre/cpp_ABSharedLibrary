#include "Armadillo.hh"


Armadillo::Armadillo()
{
}

Armadillo::~Armadillo()
{
	std::cout << "Destructeur de Armadillo" << std::endl;
}

void Armadillo::scream() const
{
	std::cout << "I'm Armadillo" << std::endl;
}

extern "C" MODULE_API IAnimal* getDLLInterface()
{
	static Armadillo g_DLLInterface;
	return &g_DLLInterface;
}
