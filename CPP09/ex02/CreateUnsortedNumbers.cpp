/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CreateUnsortedNumbers.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:45:50 by jduval            #+#    #+#             */
/*   Updated: 2023/10/05 15:07:29 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <cstdlib>
#include <cctype>
#include <cerrno>
#include <stdexcept>

static void	IsValidCharacters(char *str);
static int	ConvertToValidInteger(char *str);

void	CreateNumberVector(std::vector<int> &UnsortedNumbers, char **av)
{
	int	Value;

	for (int i = 1; av[i] != NULL; i++)
	{
		IsValidCharacters(av[i]);
		Value = ConvertToValidInteger(av[i]);
		UnsortedNumbers.push_back(Value);
	}
	return ;
}

void	CreateNumberDeque(std::deque<int> &UnsortedNumbers, char **av)
{
	int	Value;

	for (int i = 1; av[i] != NULL; i++)
	{
		IsValidCharacters(av[i]);
		Value = ConvertToValidInteger(av[i]);
		UnsortedNumbers.push_back(Value);
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
