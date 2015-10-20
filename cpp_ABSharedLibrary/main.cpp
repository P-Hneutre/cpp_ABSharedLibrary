#include "IAnimal.hh"
#include "Platypus.hh"
#include "Armadillo.hh"

int	main(int ac, char **av)
{
	Platypus *p = new Platypus();
	Armadillo *a = new Armadillo();
	IAnimal *animal = new Platypus();
	animal->scream();
	getchar();
	return 0;
}