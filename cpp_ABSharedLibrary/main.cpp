#include "IAnimal.hh"
#include "IDlLoader.hpp"
#include "UDlLoader.hpp"

int	main(int ac, char **av)
{
	try
	{
		IAnimal	*animal_module;
		IDlLoader<IAnimal> *loader = new UDlLoader<IAnimal>("platypus.so");
		loader->open();
		animal_module = loader->getInstance();
		animal_module->scream();
		loader->close();
		
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	getchar();
	return 0;
}