/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:05:27 by msuokas           #+#    #+#             */
/*   Updated: 2025/08/13 12:32:39 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){}

Contact::~Contact(){}

void Contact::setInfo(InfoType type, const std::string& value) {
	switch (type)
	{
		case FIRST_NAME: first_name = value; break;
		case LAST_NAME: last_name = value; break;
		case NICKNAME: nickname = value; break;
		case PHONENUMBER: phone_number = value; break;
		case DARKEST_SECRET: darkest_secret = value; break;
	}
}

std::string Contact::getInfo(InfoType type) const {
	switch (type)
	{
		case FIRST_NAME: return first_name;
		case LAST_NAME: return last_name;
		case NICKNAME: return nickname;
		case PHONENUMBER: return phone_number;
		case DARKEST_SECRET: return darkest_secret;
	}
	return "";
}
