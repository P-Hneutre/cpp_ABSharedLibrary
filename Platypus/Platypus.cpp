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

#ifdef _WIN32
	#define MODULE_API __declspec(dllexport)
#else
	#define MODULE_API
#endif

extern "C" MODULE_API IAnimal* getDLLInterface()
{
	static Platypus g_DLLInterface;
	return &g_DLLInterface;
}