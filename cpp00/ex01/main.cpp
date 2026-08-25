/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnajja <adnajja@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 23:40:15 by adnajja           #+#    #+#             */
/*   Updated: 2026/05/31 23:40:15 by adnajja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <limits>

int main()
{
    PhoneBook   phonebook;
    Contact     contact;
    std::string input;

    while (1)
    {
        std::cin >> input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.eof())
            return (0);
        if (input == "ADD")
            phonebook.add(contact);
        else if (input == "SEARCH")
            phonebook.search();
        else if (input == "EXIT")
            return (0);
    }
    return (0);
}