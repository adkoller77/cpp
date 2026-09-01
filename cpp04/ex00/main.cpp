/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnajja <adnajja@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 05:07:29 by adnajja           #+#    #+#             */
/*   Updated: 2026/09/01 05:07:30 by adnajja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		std::cout << "\033[33m" << "From PDF\n"<< "\033[0m";
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	{
		std::cout << "\033[33m" << "\nFrom PDF but exchanged with WrongAnimal and WrongCat\n"<< "\033[0m";
		const WrongAnimal* meta = new WrongAnimal();
		const Animal* j = new Dog();
		
		const WrongAnimal* i = new WrongCat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the WrongAnimal sound (no virtual)!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	{
		std::cout << "\033[36m" << "\nExtra test: copy constructor and operator=\n" << "\033[0m";
		Cat originalCat;
		Cat copiedCat(originalCat);          // copy constructor
		Dog originalDog;
		Dog assignedDog;
		assignedDog = originalDog;           // copy assignment operator

		std::cout << "originalCat type: " << originalCat.getType() << std::endl;
		std::cout << "copiedCat type: " << copiedCat.getType() << std::endl;
		std::cout << "assignedDog type: " << assignedDog.getType() << std::endl;
		copiedCat.makeSound();
		assignedDog.makeSound();
	}

	{
		std::cout << "\033[36m" << "\nExtra test: array of Animal* (half Dog, half Cat)\n" << "\033[0m";
		Animal* animals[4];
		for (int k = 0; k < 4; k++)
		{
			if (k % 2 == 0)
				animals[k] = new Dog();
			else
				animals[k] = new Cat();
		}
		for (int k = 0; k < 4; k++)
		{
			std::cout << animals[k]->getType() << ": ";
			animals[k]->makeSound();
		}
		for (int k = 0; k < 4; k++)
			delete animals[k]; // must trigger proper virtual destructor chaining
	}

	return 0;
}
