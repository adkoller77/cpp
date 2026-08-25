/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnajja <adnajja@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:53:16 by adnajja           #+#    #+#             */
/*   Updated: 2026/05/28 14:58:54 by adnajja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

static std::string	troncate(std::string str)
{
	if(str.length() > 10)
		return(str.substr(0, 9) + ".");
	return(str);
}

static bool	promptField(const std::string &label, std::string &out)
{
	while (1)
	{
		std::cout << label;
		if (!std::getline(std::cin, out))
			return (false);
		if (!out.empty())
			return (true);
		std::cout << "This field can't be empty." << std::endl;
	}
}

PhoneBook::PhoneBook()
{
	size = 0;
	oldest = 0;
}

void PhoneBook::add(Contact contact)
{
	if (!promptField("First Name: ", contact.first_name)
		|| !promptField("Last Name: ", contact.last_name)
		|| !promptField("Nickname: ", contact.nickname)
		|| !promptField("Phone Number: ", contact.phone_number)
		|| !promptField("Darkest Secret: ", contact.darkest_secret))
		return ;
	if(size < 8)
	{
		contacts[size] = contact;
		size++;
	}
	else
	{
		contacts[oldest] = contact;
		oldest++;
		if(oldest == 8)
			oldest = 0;
	}
}

void PhoneBook::search()
{
	std::cout << std::right
			  << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;
	for(int i = 0; i < size; i++)
	{
		std::cout << std::right
				  << std::setw(10) << i << "|"
				  << std::setw(10) << troncate(contacts[i].first_name) << "|"
				  << std::setw(10) << troncate(contacts[i].last_name) << "|"
				  << std::setw(10) << troncate(contacts[i].nickname) << std::endl;
	}
	int input;
	std::cout << "Index :";
	std::cin >> input;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (input >= 0 && input < size)
	{
		std::cout << input << "\n"
				  << contacts[input].first_name << "\n"
				  << contacts[input].last_name << "\n"
				  << contacts[input].nickname << "\n"
				  << contacts[input].phone_number << "\n"
				  << contacts[input].darkest_secret << std::endl;
	}
	else
		std::cout << "Invalid index." << std::endl;
}