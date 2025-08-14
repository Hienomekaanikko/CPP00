/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:05:05 by msuokas           #+#    #+#             */
/*   Updated: 2025/08/14 12:03:35 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string getInput() {
	std::string	input;

	std::getline(std::cin, input);
	return (input);
}

void truncAndPrint(const std::string& str) {
	if (str.length() > 10) {
		std::cout << std::setw(9) << std::right << str.substr(0, 9) << ".";
	} else {
		std::cout << std::setw(10) << std::right << str;
	}
}

void	showContacts(PhoneBook& book) {
	int	total = book.getTotal();

	std::cout << "|   Index  |First Name| Last Name| Nickname |" << std::endl;
	for (int i = 0; i < total; i++)
	{
		Contact current = book.getContact(i);
		std::cout << "|";
		truncAndPrint(std::to_string(i));
		std::cout << "|";
		truncAndPrint(current.getInfo(FIRST_NAME));
		std::cout << "|";
		truncAndPrint(current.getInfo(LAST_NAME));
		std::cout << "|";
		truncAndPrint(current.getInfo(PHONENUMBER));
		std::cout << "|" << std::endl;
	}
}

Contact	getContactInfo(PhoneBook& book) {
	Contact		new_contact;

	std::cout << "Add first name: " << std::endl;
	new_contact.setInfo(FIRST_NAME, getInput());
	std::cout << "Add last name: " << std::endl;
	new_contact.setInfo(LAST_NAME, getInput());
	std::cout << "Add phonenumber: " << std::endl;
	new_contact.setInfo(PHONENUMBER, getInput());
	std::cout << "Add nickname: " << std::endl;
	new_contact.setInfo(NICKNAME, getInput());
	std::cout << "Add darkest secret: " << std::endl;
	new_contact.setInfo(DARKEST_SECRET, getInput());
	return (new_contact);
}

void	showDetails(PhoneBook& book){
	std::cout << "Type index for contact details: " << std::endl;

	std::string index = getInput();
	if (index.empty()){
		std::cout << "No index was given..." << std::endl;
		return ;
	}
	if (std::stoi(index) > book.getTotal() || std::stoi(index) < 0) {
		std::cout << "Index out of range..." << std::endl;
		return ;
	}
	Contact Person;
	Person = book.getContact(std::stoi(index));
	std::cout << "First name: " << Person.getInfo(FIRST_NAME) << std::endl;
	std::cout << "Last name: " << Person.getInfo(LAST_NAME) << std::endl;
	std::cout << "Phone number: " << Person.getInfo(PHONENUMBER) << std::endl;
	std::cout << "Nickname: " << Person.getInfo(NICKNAME) << std::endl;
	std::cout << "Darkest secret: " << Person.getInfo(DARKEST_SECRET) << std::endl;
}

int	main(int argc, char **argv) {
	PhoneBook	book;
	std::string	input;

	if (argc != 1)
		std::cout << "Invalid input" << std::endl;
	while (true)
	{
		std::cout << "Type EXIT, ADD or SEARCH" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::cout << "Exiting..." << std::endl;
			break ;
		}
		if (input == "EXIT")
			break;
		else if (input == "ADD") {
			book.addContact(getContactInfo(book));
		}
		else if (input == "SEARCH") {
			if (book.getTotal() == 0)
				std::cout << "The phonebook is empty..." << std::endl;
			else
			{
				showContacts(book);
				showDetails(book);
			}
		}
	}
	return (0);
}
