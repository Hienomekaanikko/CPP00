/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:00:34 by msuokas           #+#    #+#             */
/*   Updated: 2025/07/09 15:38:44 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>

enum	InfoType
{
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONENUMBER,
	DARKEST_SECRET
};

class Contact
{
	public:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};

class	PhoneBook
{
	public:
		Contact	person[8];
		int		curr;
		int		total;
};

#endif
