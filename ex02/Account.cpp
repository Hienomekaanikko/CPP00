/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:35:17 by msuokas           #+#    #+#             */
/*   Updated: 2025/07/09 16:25:32 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int	Account::getNbWithdrawals(void)
{
	return(_totalNbWithdrawals);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}


int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	main(void)
{

}
