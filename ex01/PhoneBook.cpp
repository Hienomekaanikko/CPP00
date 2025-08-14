/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:54:21 by msuokas           #+#    #+#             */
/*   Updated: 2025/08/13 14:07:27 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	total = 0;
	curr = 0;
}

PhoneBook::~PhoneBook(){}

bool PhoneBook::addContact(const Contact& contact) {
	contacts[curr] = contact;
	curr = (curr + 1) % 8;
	if (total < 8) total++;
		return true;
}

Contact PhoneBook::getContact(int index) const {
	return contacts[index];
}

int	PhoneBook::getTotal() const {
	return total;
}

