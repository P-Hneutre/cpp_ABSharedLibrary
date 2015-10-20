#pragma once
class IAnimal
{
	public:
		virtual	~IAnimal() {};

	public:
		virtual void	scream() const = 0;
};

