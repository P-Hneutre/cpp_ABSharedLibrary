#include "IAnimal.hh"
#include "IDlLoader.hpp"

#ifdef __unix__

#include "UDlLoader.hpp"

#elif defined _WIN32

#include "WDlLoader.hpp"

#endif

int	main(int ac, char **av)
{
	try
	{
		IAnimal	*animal_module;
#ifdef __unix__
		IDlLoader<IAnimal> *loader = new UDlLoader<IAnimal>("platypus.so");
#elif defined _WIN32
		IDlLoader<IAnimal> *loader = new WDlLoader<IAnimal>("platypus.dll");
#endif
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