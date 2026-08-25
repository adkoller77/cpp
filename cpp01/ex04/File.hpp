/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnajja <adnajja@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 23:34:33 by adnajja           #+#    #+#             */
/*   Updated: 2026/08/20 00:00:00 by adnajja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HPP
# define FILE_HPP

# include <string>
# include <fstream>

class File
{
	private:
		std::string filename;
		std::string s1;
		std::string s2;

	public:
		File(std::string filename, std::string s1, std::string s2);
		bool replace();
};

#endif
