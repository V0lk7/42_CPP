/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CreateList.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:45:50 by jduval            #+#    #+#             */
/*   Updated: 2023/10/02 13:40:59 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <cstdlib>
#include <cctype>
#include <cerrno>
#include <stdexcept>

static void	IsValidCharacters(char *str);
static int	ConvertToValidInteger(char *str);

void	CreateVList(std::vector<int> &VList, char **av)
{
	int	Value;

	for (int i = 1; av[i] != NULL; i++)
	{
		IsValidCharacters(av[i]);
		Value = ConvertToValidInteger(av[i]);
		VList.push_back(Value);
	}
	return ;
}

static void	IsValidCharacters(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (isdigit(str[i]) == 0)
			throw (std::runtime_error("Non valid argument."));
	}
}

static int	ConvertToValidInteger(char *str)
{
	long int	Value = strtol(str, NULL, 10);

	if (errno == ERANGE || Value > 2147483647)
		throw (std::runtime_error("Value out of range."));
	else 
		return (static_cast<int>(Value));
}
