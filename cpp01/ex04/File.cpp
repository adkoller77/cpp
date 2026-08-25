/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnajja <adnajja@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 23:34:33 by adnajja           #+#    #+#             */
/*   Updated: 2026/08/20 00:00:00 by adnajja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"
#include <iostream>
#include <iterator>

File::File(std::string filename, std::string s1, std::string s2)
{
	this->filename = filename;
	this->s1 = s1;
	this->s2 = s2;
}

bool File::replace()
{
	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: cannot open file \"" << filename << "\"" << std::endl;
		return false;
	}

	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: cannot create output file \"" << filename << ".replace\"" << std::endl;
		return false;
	}

	std::string content((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
	std::string result;
	result.reserve(content.size());

	size_t pos = 0;
	size_t len = s1.size();

	while (pos < content.size())
	{
		if (len > 0 && content.compare(pos, len, s1) == 0)
		{
			result += s2;
			pos += len;
		}
		else
		{
			result += content[pos];
			++pos;
		}
	}

	outfile << result;
	return true;
}
