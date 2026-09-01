/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnajja <adnajja@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 05:07:29 by adnajja           #+#    #+#             */
/*   Updated: 2026/09/01 05:07:30 by adnajja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// constructors
Animal::Animal() : _type("Default")
{
	std::cout << "Animal default constructor called\n";
}

Animal::Animal (std::string type) : _type(type)
{
	std::cout << "Animal constructor called\n";
}

Animal::Animal(const Animal &other) : _type(other._type)
{
	std::cout << "Animal copy constructor called\n";
}

Animal &Animal::operator=(const Animal &other)
{
	_type = other._type;
	std::cout << "Animal copy assignment constructor called\n";
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal deconstructor called\n";
}


// member functions
void Animal::makeSound() const
{
	std::cout << "Animal could make several different sounds\n";
}

std::string Animal::getType() const
{
	return (_type);
}

