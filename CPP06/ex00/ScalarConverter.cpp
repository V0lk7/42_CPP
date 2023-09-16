/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:17:59 by jduval            #+#    #+#             */
/*   Updated: 2023/09/16 16:21:13 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Utils.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void) rhs;
	return (*this);
}

void	ScalarConverter::convert(std::string input)
{
	(void) input;
	ScalarConverter		obj;
	int const			OriginType = FindOriginType(input);

	if (OriginType < 0)
		return ;
/*
	void	*(ScalarConverter::ConvertMethods[NBR_OF_CONVERT])(void *data, int type) = {	ConvertToChar,
																							ConvertToInt, 
																							ConvertToFloat, 
																							ConvertToDouble};
	try{
		void	*PrimalTypeConverted = FirstConversion(OriginType, input);
	}
	catch (std::execption &e){
		std::cerr << e.what() << std::endl;
		return ;
	}
	for (int i = 0; i < NBR_OF_CONVERT; i++)
	{
		if (i == OriginType)
			continue ;
		else
			ConvertMethods[i](PrimalTypeConverted, OriginType);
	}
	delete PrimalTypeConverted;
 */	
	return ;
}
