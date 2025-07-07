/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:24:25 by msuokas           #+#    #+#             */
/*   Updated: 2025/07/07 11:42:09 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	case_up(char *str)
{
	int	i = 0;
	while (str[i])
	{
		std::cout << (char)std::toupper(str[i]);
		i++;
	}
	std::cout << " ";
}

int	main(int argc, char *argv[])
{
	int	i = 1;

	if (argc <= 1)
		std::cout << "Type at least one argument\n";
	while (argv[i])
	{
		case_up(argv[i]);
		i++;
	}
	std::cout << "\n";
}
