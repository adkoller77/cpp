#include "Zombie.hpp"

int main()
{
	Zombie *walking_dead = zombieHorde(5, "tata_la_zaza");

	for (int i = 0; i < 5; i++)
		walking_dead[i].announce();
	delete[] walking_dead;
	return (0);
}
