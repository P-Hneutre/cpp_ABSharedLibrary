#include "IAnimal.hh"
#include "IDlManager.hpp"
#include "IDlLoader.hpp"

#ifdef __unix__

#include "UDlLoader.hpp"
#include "UDlManager.hpp"

#elif defined _WIN32

#include "WDlLoader.hpp"
#include "WDlManager.hpp"

#endif

int	main(int ac, char **av)
{
	try
	{
#ifdef __unix__
		IDlManager<IAnimal> *dl = new UDlManager<IAnimal>();
#elif defined _WIN32
		IDlManager<IAnimal> *dl = new WDlManager<IAnimal>();
#endif
		dl->loadAll("../plugins/");
		dl->getObject("Platypus")->scream();
		dl->getObject("Armadillo")->scream();

		delete dl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
