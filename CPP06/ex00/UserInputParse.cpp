/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInputParse.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:11:27 by jduval            #+#    #+#             */
/*   Updated: 2023/09/17 16:43:38 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <regex.h>
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

bool	IsZero(std::string input, int OriginalType)
{
	regex_t	regex;
	bool	match = false;

	switch(OriginalType){
		case FLOAT :
			//need a security in case of regcomp fail
			regcomp(&regex, RegZero[0], REG_EXTENDED);
			if (regexec(&regex, input.c_str(), 0, NULL, 0) == 0)
				match = true;
			break ;
		case DOUBLE :
			//need a security in case of regcomp fail
			regcomp(&regex, RegZero[1], REG_EXTENDED);
			if (regexec(&regex, input.c_str(), 0, NULL, 0) == 0)
				match = true;
			break ;
	}
	regfree(&regex);
	return (match);
}
