/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:05:30 by msuokas           #+#    #+#             */
/*   Updated: 2025/08/13 15:49:53 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

enum InfoType {
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONENUMBER,
	DARKEST_SECRET
};

class Contact {
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	public:
		Contact();
		~Contact();
		void setInfo(InfoType type, const std::string& value);
		std::string getInfo(InfoType type) const;
};

#endif
