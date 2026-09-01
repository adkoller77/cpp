/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnajja <adnajja@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 05:07:29 by adnajja           #+#    #+#             */
/*   Updated: 2026/09/01 05:07:30 by adnajja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// constructors
Dog::Dog() : AAnimal()
{
	std::cout << "Dog default constructor called\n";
	_type = "Dog";
	_own_brain = new Brain();
}

Dog::Dog (std::string type) : AAnimal(type)
{
	std::cout << "Dog constructor called\n";
	_type = type;
	_own_brain = new Brain();
}

Dog::Dog(const Dog &other) : AAnimal(other)
{
	std::cout << "Dog copy constructor called\n";
	_own_brain = new Brain(*(other._own_brain));
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment constructor called\n";
	if (this == &other)
		return (*this);
	_type = other._type;
	delete _own_brain;
	_own_brain = new Brain(*(other._own_brain));
	return (*this);
}

Dog::~Dog()
{
	delete _own_brain;
	std::cout << "Dog deconstructor called\n";
}


// member functions
void Dog::makeSound() const
{
	std::cout << "Wau Wau Wau\n";
}

std::string Dog::getIdea(int idea_nr) const
{
	if (idea_nr >= 0 && idea_nr < 100)
		return (_own_brain->ideas[idea_nr]);
	else
		return ("Dog brain just have 100 ideas");
}

void Dog::setIdea(int idea_nr, std::string new_idea)
{
	if (idea_nr >= 0 && idea_nr < 100)
		_own_brain->ideas[idea_nr] = new_idea;
	else
		std::cout << "Dog brain can just save 100 ideas";
}
