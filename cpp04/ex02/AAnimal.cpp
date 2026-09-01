/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnajja <adnajja@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 05:07:29 by adnajja           #+#    #+#             */
/*   Updated: 2026/09/01 05:07:30 by adnajja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// constructors
AAnimal::AAnimal() : _type("Default")
{
	std::cout << "AAnimal default constructor called\n";
}

AAnimal::AAnimal (std::string type) : _type(type)
{
	std::cout << "AAnimal constructor called\n";
}

AAnimal::AAnimal(const AAnimal &other) : _type(other._type)
{
	std::cout << "AAnimal copy constructor called\n";
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	_type = other._type;
	std::cout << "AAnimal copy assignment constructor called\n";
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal deconstructor called\n";
}


// member functions
void AAnimal::makeSound() const
{
	std::cout << "AAnimal could make several different sounds\n";
}

std::string AAnimal::getType() const
{
	return (_type);
}
