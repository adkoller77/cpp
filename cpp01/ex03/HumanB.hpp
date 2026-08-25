/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnajja <adnajja@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:44:57 by adnajja           #+#    #+#             */
/*   Updated: 2026/06/11 18:55:19 by adnajja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include "Weapon.hpp"
class HumanB{
    private:
        std::string name;
        Weapon* weapon;
    public:
        void attack();
        void setWeapon(Weapon& weapon);
        HumanB(std::string name);
};
#endif