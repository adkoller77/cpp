/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnajja <adnajja@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 22:35:24 by adnajja           #+#    #+#             */
/*   Updated: 2026/05/19 19:27:08 by adnajja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class   Contact {
	public:
		Contact();

        std::string first_name;
        std::string last_name;
        std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

#endif