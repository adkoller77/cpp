/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnajja <adnajja@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 05:07:29 by adnajja           #+#    #+#             */
/*   Updated: 2026/09/01 05:07:30 by adnajja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// constructors
Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called\n";
	_type = "Cat";
	_own_brain = new Brain();
}

Cat::Cat (std::string type) : Animal(type)
{
	std::cout << "Cat constructor called\n";
	_type = type;
	_own_brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called\n";
	_own_brain = new Brain(*(other._own_brain));
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment constructor called\n";
	if (this == &other)
		return (*this);
	_type = other._type;
	delete _own_brain;
	_own_brain = new Brain(*(other._own_brain));
	return (*this);
}

Cat::~Cat()
{
	delete _own_brain;
	std::cout << "Cat deconstructor called\n";
}


// member functions
void Cat::makeSound() const
{
	std::cout << "Miau Miau Miau\n";
}

std::string Cat::getIdea(int idea_nr) const
{
	if (idea_nr >= 0 && idea_nr < 100)
		return (_own_brain->ideas[idea_nr]);
	else
		return ("Cat brain just have 100 ideas");
}

void Cat::setIdea(int idea_nr, std::string new_idea)
{
	if (idea_nr >= 0 && idea_nr < 100)
		_own_brain->ideas[idea_nr] = new_idea;
	else
		std::cout << "Cat brain can just save 100 ideas";
}
