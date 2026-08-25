/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnajja <adnajja@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 13:11:27 by adnajja           #+#    #+#             */
/*   Updated: 2026/06/12 17:01:59 by adnajja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}
void HumanB::attack()
{
	if(weapon != NULL)
	{
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	}
}
void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}