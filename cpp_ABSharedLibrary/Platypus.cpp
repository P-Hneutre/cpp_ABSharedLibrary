#include "Platypus.hh"

Platypus::Platypus()
{
}

Platypus::~Platypus()
{
	std::cout << "Destructeur de Platypus" << std::endl;
}

void Platypus::scream() const
{
	std::cout << "I'm Platypus" << std::endl;
}

extern "C"
{
	IAnimal* load_plugin()
	{
		return new Platypus();
	}
}
