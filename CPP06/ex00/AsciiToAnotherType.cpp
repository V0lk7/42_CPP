/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AsciiToAnotherType.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:52:36 by jduval            #+#    #+#             */
/*   Updated: 2023/09/17 11:40:06 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <string>

int	AsciiToInt(std::string input)
{
	int	ValueConverted;
	std::istringstream	ConvertBox(input);

	if (!(ConvertBox >> ValueConverted))
		ValueConverted = 0;
	return (ValueConverted);
}

float	AsciiToFloat(std::string input)
{
	float	ValueConverted;
	std::istringstream	ConvertBox(input);

	if (!(ConvertBox >> ValueConverted))
		ValueConverted = 0.0f;
	return (ValueConverted);
}

double	AsciiToDouble(std::string input)
{
	double	ValueConverted;
	std::istringstream	ConvertBox(input);

	if (!(ConvertBox >> ValueConverted))
		ValueConverted = 0.0;
	return (ValueConverted);
}
