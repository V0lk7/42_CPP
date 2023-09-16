/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInputParse.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:11:27 by jduval            #+#    #+#             */
/*   Updated: 2023/09/16 16:45:25 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <regex.h>
#include <sstream>
#include "Utils.hpp"

bool	CheckNumberOfArguments(int NumberOfArgs)
{
	if (NumberOfArgs == 1)
	{
		std::cerr << "One argument is required." << std::endl;
		return (false);
	}
	else if (NumberOfArgs > 2)
	{
		std::cerr << "Only one argument is required." << std::endl;
		return (false);
	}
	else
		return (true);
}

static int	IsNormalType(std::string input);
static int	IsParticularFloat(std::string input);
static int	IsParticularDouble(std::string input);
static int	IsParticularType(std::string input);

int	FindOriginType(std::string input)
{
	int	type = -1;

	type = IsParticularType(input);
	if (type > NBR_OF_TYPE)
		return (type);
	type = IsNormalType(input);
	return (type);
}

static int	IsParticularType(std::string input)
{
	int	type = 0;

	type = IsParticularFloat(input);
	if (type > NBR_OF_TYPE)
		return (type);
	type = IsParticularDouble(input);
	return (type);
}

static int	IsParticularFloat(std::string input)
{
	regex_t	regex;

	for (int i = 0; i < PARTICULAR_CASE_NBR; i++)
	{
		if (regcomp(&regex, RegParticularFloat[i], REG_EXTENDED) != 0)
			return (-1);
		if (regexec(&regex, input.c_str(), 0, NULL, 0) == 0)
		{
			regfree(&regex);
			return (FLOAT_SPE_CASE);
		}
		regfree(&regex);
	}
	return (0);
}

static int	IsParticularDouble(std::string input)
{
	regex_t	regex;

	for (int i = 0; i < PARTICULAR_CASE_NBR; i++)
	{
		if (regcomp(&regex, RegParticularDouble[i], REG_EXTENDED) != 0)
			return (-1);
		if (regexec(&regex, input.c_str(), 0, NULL, 0) == 0)
		{
			regfree(&regex);
			return (DOUBLE_SPE_CASE);
		}
		regfree(&regex);
	}
	return (0);
}

static int IsNormalType(std::string input)
{
	regex_t	regex;

	for (int i = 0; i < NBR_OF_TYPE; i++)
	{
		if (regcomp(&regex, RegNormalCase[i], REG_EXTENDED) != 0)
			return (-1);
		if (regexec(&regex, input.c_str(), 0, NULL, 0) == 0)
		{
			regfree(&regex);
			return (i);
		}
		regfree(&regex);
	}
	return (ERROR_TYPE);
}

static int		AsciiToInt(std::string input);
static float	AsciiToFloat(std::string input);
static double	AsciiToDouble(std::string input);

void	*FirstConversion(int const OriginType, std::string input)
{
	switch (OriginType){
		case INT :
		{
			std::cout << "hey" << std::endl;
			int	*ValueConverted = new int;
			*ValueConverted = AsciiToInt(input);
			return (static_cast<void *>(ValueConverted));
		}
		case CHAR :
		{
			char	*ValueConverted = new char[1];
			*ValueConverted = input.c_str()[0];
			return (static_cast<void *>(ValueConverted));
		}
		case FLOAT :
		{
			float	*ValueConverted = new float;
			*ValueConverted = AsciiToFloat(input);
			return (static_cast<void *>(ValueConverted));
		}
		case DOUBLE :
		{
			double	*ValueConverted = new double;
			*ValueConverted = AsciiToDouble(input);
			return (static_cast<void *>(ValueConverted));
		}
		default :
			return (NULL);
	}
}

static int	AsciiToInt(std::string input)
{
	int	ValueConverted;
	std::istringstream	ConvertBox(input);

	if (!(ConvertBox >> ValueConverted))
		ValueConverted = 0;
	return (ValueConverted);
}

static float	AsciiToFloat(std::string input)
{
	float	ValueConverted;
	std::istringstream	ConvertBox(input);

	if (!(ConvertBox >> ValueConverted))
		ValueConverted = 0.0f;
	return (ValueConverted);
}

static double	AsciiToDouble(std::string input)
{
	double	ValueConverted;
	std::istringstream	ConvertBox(input);

	if (!(ConvertBox >> ValueConverted))
		ValueConverted = 0.0;
	return (ValueConverted);
}

void	FreeMetamorphicData(void *MetamorphicData, int const OriginType)
{
	switch (OriginType){
		case INT :
			delete static_cast<int *>(MetamorphicData);
			break ;
		case CHAR :
			delete[] static_cast<char *>(MetamorphicData);
			break ;
		case FLOAT :
			delete static_cast<float *>(MetamorphicData);
			break ;
		case DOUBLE :
			delete static_cast<double *>(MetamorphicData);
			break ;
		default :
			break ;
	}
}
