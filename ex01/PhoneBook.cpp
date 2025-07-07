/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:00:31 by msuokas           #+#    #+#             */
/*   Updated: 2025/07/07 16:26:43 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	is_digits(std::string value)
{
	int	i = 0;

	while (value[i])
	{
		if (!std::isdigit(value[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ask_index(PhoneBook& contacts, std::string index)
{
	int	converted_index;

	std::cout << "Enter the index of a person for more information\n";
	while (1)
	{
		std::getline(std::cin, index);
		if (index == "EXIT")
			return (-1);
		if (!is_digits(index))
		{
			std::cout << "Invalid input: The index can be only positive digits.\n";
			continue ;
		}
		converted_index = std::stoi(index);
		if (converted_index >= contacts.total || converted_index < 0)
			std::cout << "Out of range, try again\n";
		else
			break ;
	}
	return (converted_index);
}

void	search_contact(PhoneBook& contacts)
{
	std::string	index;
	int			i = 0;
	int			id;

	while (i < contacts.total)
	{
		std::cout << std::setw(10) << std::right << i << "|";
		std::cout << std::setw(10) << std::right << contacts.person[i].first_name << "|";
		std::cout << std::setw(10) << std::right << contacts.person[i].last_name << "|";
		std::cout << std::setw(10) << std::right << contacts.person[i].nickname << "\n";
		i++;
	}
	id = ask_index(contacts, index);
	if (id == -1)
		return ;
	else
	{
		std::cout << contacts.person[id].first_name << "\n";
		std::cout << contacts.person[id].last_name << "\n";
		std::cout << contacts.person[id].phonenumber << "\n";
		std::cout << contacts.person[id].nickname << "\n";
		std::cout << contacts.person[id].darkest_secret << "\n";
	}
}

std::string	truncate(const std::string& line)
{
	std::string	new_line;

	if (line.length() <= 10)
		return (line);
	new_line = line.substr(0, 10);
	new_line[9] = '.';
	return (new_line);
}

int	add_contact(PhoneBook& contacts)
{
	std::string	line;
	std::string trunc_line;

	if (contacts.curr == 8)
		contacts.curr = 0;
	std::cout << "Add first name: \n";
	if (!std::getline(std::cin, line))
	{
		std::cout << "\nInput error or EOF detected.\n";
		return (0);
	}
	if (line == "")
	{
		std::cout << "Contact creation failed: Empty fields not allowed\n";
		return (1);
	}
	trunc_line = truncate(line);
	line = "";
	contacts.person[contacts.curr].first_name = trunc_line;
	std::cout << "Add last name: \n";
	if (!std::getline(std::cin, line))
	{
		std::cout << "\nInput error or EOF detected.\n";
		return (0);
	}
	if (line == "")
	{
		std::cout << "Contact creation failed: Empty fields not allowed\n";
		return (1);
	}
	trunc_line = truncate(line);
	line = "";
	contacts.person[contacts.curr].last_name =  trunc_line;
	std::cout << "Add nickname: \n";
	if (!std::getline(std::cin, line))
	{
		std::cout << "\nInput error or EOF detected.\n";
		return (0);
	}
	if (line == "")
	{
		std::cout << "Contact creation failed: Empty fields not allowed\n";
		return (1);
	}
	trunc_line = truncate(line);
	line = "";
	contacts.person[contacts.curr].nickname =  trunc_line;
	std::cout << "Add phonenumber: \n";
	if (!std::getline(std::cin, line))
	{
		std::cout << "\nInput error or EOF detected.\n";
		return (0);
	}
	if (line == "")
	{
		std::cout << "Contact creation failed: Empty fields not allowed\n";
		return (1);
	}
	trunc_line = truncate(line);
	line = "";
	if (!is_digits(line))
	{
		std::cout << "Contact creation failed: Phone number can be only numbers... :(";
		return (1);
	}
	trunc_line = truncate(line);
	line = "";
	contacts.person[contacts.curr].phonenumber =  trunc_line;
	std::cout << "Add darkest secret: \n";
	if (!std::getline(std::cin, line))
	{
		std::cout << "\nInput error or EOF detected.\n";
		return (0);
	}
	if (line == "")
	{
		std::cout << "Contact creation failed: Empty fields not allowed\n";
		return (1);
	}
	trunc_line = truncate(line);
	line = "";
	contacts.person[contacts.curr].darkest_secret =  trunc_line;
	if (contacts.total < 8)
		contacts.total++;
	contacts.curr++;
	return (1);
}

int	main(void)
{
	std::string	input;
	PhoneBook	contacts;

	while (1)
	{
		std::cout << "Type ADD to add a contact, SEARCH to look for contacts or EXIT to exit the phonebook.\n";
		if (!std::getline(std::cin, input))
		{
			std::cout << "\nInput error or EOF detected.\n";
			break ;
		}
		if (input == "EXIT")
			break;
		else if (input == "ADD")
		{
			if (!add_contact(contacts))
				break ;
		}
		else if (input == "SEARCH")
			search_contact(contacts);
		input = "";
	}
	return (0);
}
