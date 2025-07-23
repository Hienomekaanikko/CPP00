/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:00:31 by msuokas           #+#    #+#             */
/*   Updated: 2025/07/09 15:41:39 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void truncate(const std::string& line)
{
	int	len = 0;

	while (line[len])
		len++;
	if (len > 10)
	{
		for (int i = 0; i < 9; ++i)
			std::cout << line[i];
		std::cout << "." << std::endl;
	}
	else
	{
		for (int i = 0; i < 10 - len; ++i)
			std::cout << " " << std::endl;
		for (int i = 0; i < len; ++i)
			std::cout << line[i] << std::endl;
	}
}

bool	is_all_digits(const std::string& str)
{
	for (char c : str)
	{
		if (!std::isdigit(c))
			return (false);
	}
	return (!str.empty());
}

void	print_column_headers(int status)
{
	truncate ("Index: ");
	std::cout << "|" << std::endl;
	truncate ("First nam: ");
	std::cout << "|" << std::endl;
	truncate ("Last nam: ");
	std::cout << "|" << std::endl;
	truncate ("Nickname: ");
	if (status == 2)
	{
		std::cout << "|" << std::endl;
		truncate ("Phone num: ");
		std::cout << "|" << std::endl;
		truncate ("Darkest sec: ");
	}
}

void	show_info(PhoneBook& book)
{
	std::string	input;
	int			i = 0;
	int			index = -1;

	print_column_headers(1);
	while (i < book.total)
	{
		truncate(std::to_string(i));
		std::cout << "|" << std::endl;
		truncate(book.person[i].first_name);
		std::cout << "|" << std::endl;
		truncate(book.person[i].last_name);
		std::cout << "|" << std::endl;
		truncate(book.person[i].nickname);
		i++;
	}
	std::cout << "Type index for more information: " << std::endl;
	std::cin >> input;
	if (is_all_digits(input))
	{
		index = std::stoi(input);
		if (index > book.total - 1)
		{
			std::cout << "ERROR: Index out of range" << std::endl;
			return ;
		}
	}
	else
	{
		std::cout << "ERROR: Index must be positive value within the range of available indexes" << std::endl;
		return ;
	}
	print_column_headers(2);
	if (index >= 0 && index < book.total)
	{
		truncate(std::to_string(index));
		std::cout << "|" << std::endl;
		truncate(book.person[index].first_name);
		std::cout << "|" << std::endl;
		truncate(book.person[index].last_name);
		std::cout << "|" << std::endl;
		truncate(book.person[index].nickname);
		std::cout << "|" << std::endl;
		truncate(book.person[index].phone_number);
		std::cout << "|" << std::endl;
		truncate(book.person[index].darkest_secret);
		std::cout << "\n" << std::endl;
	}
}

int	add_info(PhoneBook& book, InfoType type)
{
	while (1)
	{
		if (type == FIRST_NAME)
		{
			std::cout << "First name (can't leave empty): " << std::endl;
			std::cin >> book.person[book.curr].first_name;
			if (!book.person[book.curr].first_name.empty())
				break ;
			else
				return (-1);
		}
		else if (type == LAST_NAME)
		{
			std::cout << "Last name (can't leave empty): " << std::endl;
			std::cin >> book.person[book.curr].last_name;
			if (!book.person[book.curr].last_name.empty())
				break ;
			else
				return (-1);
		}
		else if (type == NICKNAME)
		{
			std::cout << "Nickname (can't leave empty): " << std::endl;
			std::cin >> book.person[book.curr].nickname;
			if (!book.person[book.curr].nickname.empty())
				break ;
			else
				return (-1);
		}
		else if (type == PHONENUMBER)
		{
			std::cout << "Phonenumber (can't leave empty): " << std::endl;
			std::cin >> book.person[book.curr].phone_number;
			if (!book.person[book.curr].phone_number.empty())
				break ;
			else
				return (-1);
		}
		else if (type == DARKEST_SECRET)
		{
			std::cout << "Darkest secret (can't leave empty): " << std::endl;
			std::cin >> book.person[book.curr].darkest_secret;
			if (!book.person[book.curr].darkest_secret.empty())
				break ;
			else
				return (-1);
		}
	}
	return (0);
}

int	add_contact(PhoneBook& book)
{
	if (add_info(book, FIRST_NAME) == -1)
		return (-1);
	if (add_info(book, LAST_NAME) == -1)
		return (-1);
	if (add_info(book, NICKNAME) == -1)
		return (-1);
	if (add_info(book, PHONENUMBER) == -1)
		return (-1);
	if (add_info(book, DARKEST_SECRET) == -1)
		return (-1);
	if (book.total < 8)
		book.total++;
	book.curr = (book.curr + 1) % 8;
	return (1);
}

int	main(void)
{
	PhoneBook	book;
	std::string	action;

	book.curr = 0;
	book.total = 0;
	while (1)
	{
		std::cout << "Type ADD to add a contact, SEARCH to look for a contact and EXIT to exit" << std::endl;
		std::cin >> action;
		if (action.empty())
			break ;
		if (action == "EXIT")
			break ;
		else if (action == "ADD")
		{
			if (add_contact(book) == -1)
				break;
		}
		else if (action == "SEARCH")
			show_info(book);
		else
			continue ;
	}
	return (0);
}
