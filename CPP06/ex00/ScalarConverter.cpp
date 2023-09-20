/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:17:59 by jduval            #+#    #+#             */
/*   Updated: 2023/09/20 13:36:03 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Utils.hpp"
#include <iostream>
#include <cstring>
#include <cfloat>
#include <cmath>

bool		ScalarConverter::_intOverflow = false;
bool		ScalarConverter::_floatOverflow = false;
bool		ScalarConverter::_doubleOverflow = false;

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

char const	*RegexException::what(void) const throw()
{
	return ("Regex failed");
}

void	ScalarConverter::convert(std::string input)
{
	ScalarConverter		obj;
	int					OriginType;
	int					OriginTypeTmp;
	void				*MetamorphicData;

	try{
		OriginType = FindOriginType(input);
		if (OriginType < 0)
			return ;
		MetamorphicData = firstConversion(OriginType, input);
	}
	catch (RegexException &e){
		std::cerr << "Error Occured : " << e.what() << std::endl; 
		return ;
	}
	catch (std::exception &e){
		std::cerr << "Error Occured : " << e.what() << std::endl; 
		return ;
	}
	OriginTypeTmp = checkOverflow(OriginType);
	MethodsPtr	*ConvertMethods[4] = {convertToChar, convertToInt, convertToFloat, convertToDouble};
	for (int i = 0; i < NBR_OF_TYPE; i++)
		ConvertMethods[i](MetamorphicData, OriginType);
	freeMetamorphicData(MetamorphicData, OriginType);
	return ;
}

void	*ScalarConverter::firstConversion(int OriginType, std::string input)
{
	switch (OriginType){
		case INT :
		{
			int	*ValueConverted = new int;
			*ValueConverted = AsciiToInt(input);
			if (*ValueConverted == 0 && input.size() != 1)
				_intOverflow = true;
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
			if (*ValueConverted == 0.0f && IsZero(input, OriginType) == false)
				_floatOverflow = true;
			return (static_cast<void *>(ValueConverted));
		}
		case DOUBLE :
		{
			double	*ValueConverted = new double;
			*ValueConverted = AsciiToDouble(input);
			if (*ValueConverted == 0.0 && IsZero(input, OriginType) == false)
				_doubleOverflow = true;
			return (static_cast<void *>(ValueConverted));
		}
		default :{
			char	*ValueConverted = new char[input.size() + 1];
			std::strcpy(ValueConverted, input.c_str());
			return (static_cast<void *>(ValueConverted));
		}
	}
}

int	ScalarConverter::checkOverflow(int OriginType)
{
	switch (OriginType){
		case INT :
			if (_intOverflow == true)
				OriginType = ERROR_TYPE;
			break ;
		case FLOAT :
			if (_floatOverflow == true)
				OriginType = ERROR_TYPE;
			break ;
		case DOUBLE :
			if (_doubleOverflow == true)
				OriginType = ERROR_TYPE;
			break ;
		default :
			break ;
	}
	return (OriginType);
}

void	ScalarConverter::convertToChar(void *MetamorphicData, int OriginType)
{
	std::cout << "char: ";
	char	data;

	switch (OriginType){
		case INT :
			data = static_cast<char>(*(static_cast<int *>(MetamorphicData)));
			break ;
		case FLOAT :
			data = static_cast<char>(*(static_cast<float *>(MetamorphicData)));
			break ;
		case DOUBLE :
			data = static_cast<char>(*(static_cast<double *>(MetamorphicData)));
			break ;
		case CHAR :
			data = *(static_cast<char *>(MetamorphicData));
			break ;
		default :
			std::cout << "Impossible" << std::endl;
			return ;
	}
	if (data < 0 || data > 127)
		std::cout << "Impossible" << std::endl;
	else if (isgraph(data) != 0)
		std::cout << data << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	return ;
}

void	ScalarConverter::convertToInt(void *MetamorphicData, int OriginType)
{
	std::cout << "int: ";

	switch (OriginType){
		case INT :
			std::cout << *(static_cast<int *>(MetamorphicData)) << std::endl;
			break ;
		case FLOAT :{
			float	tmp = *(static_cast<float *>(MetamorphicData));
			if (tmp > 2147483647.0f || tmp < -2147483648.0f)
				std::cout << "Impossible" << std::endl;
			else
				std::cout << static_cast<int>(tmp) << std::endl;
			return ;
		}
		case DOUBLE :{
			double	tmp = *(static_cast<double *>(MetamorphicData));
			if (tmp > 2147483647.0 || tmp < -2147483648.0)
				std::cout << "Impossible" << std::endl;
			else
				std::cout << static_cast<int>(tmp) << std::endl;
			return ;
		}
		case CHAR :{
			std::cout << static_cast<int>(*(static_cast<char *>(MetamorphicData))) << std::endl;
			return ;
		}
		default :
			std::cout << "Impossible" << std::endl;
			return ;
	}
}

void	ScalarConverter::convertToFloat(void *MetamorphicData, int OriginType)
{
	std::cout << "float: ";

	switch (OriginType){
		case INT :{
			int	tmp = *(static_cast<int *>(MetamorphicData));
			std::cout << static_cast<float>(tmp) << ".0f" << std::endl;
			return ;
		}
		case FLOAT :{
			float	IntPart;
			float	OriginalValue = *(static_cast<float *>(MetamorphicData));
			float	FractPart = std::modf(OriginalValue, &IntPart);
			std::cout << OriginalValue;
			if (FractPart == 0.0f)
				std::cout << ".0";
			std::cout << "f" << std::endl;
			return ;
		}
		case DOUBLE :{
			double	IntPart;
			double	OriginalValue = *(static_cast<double *>(MetamorphicData));
			if (OriginalValue > FLT_MAX || OriginalValue < (FLT_MAX * (-1.0f) + 1.0f))
				std::cout << "Impossible" << std::endl;
			else
			{
				std::cout << static_cast<float>(OriginalValue);
				double	FractPart = std::modf(OriginalValue, &IntPart);
				if (FractPart == 0.0f)
					std::cout << ".0";
				std::cout << "f" << std::endl;
			}
			return ;
		}
		case CHAR :{
			std::cout << static_cast<float>(*(static_cast<char *>(MetamorphicData)));
			std::cout << ".0f" << std::endl;
			return ;
		}
		case FLOAT_SPE_CASE :{
			std::cout << static_cast<char *>(MetamorphicData) << std::endl;
			return ;
		}
		case DOUBLE_SPE_CASE :{
			std::cout << static_cast<char *>(MetamorphicData) << "f" << std::endl;
			return ;	
		}
		default :
			std::cout << "Impossible" << std::endl;
			return ;
	}
}

void	ScalarConverter::convertToDouble(void *MetamorphicData, int OriginType)
{
	std::cout << "double: ";

	switch (OriginType){
		case INT :{
			double	OriginalValue = static_cast<double>(*(static_cast<int *>(MetamorphicData)));
			std::cout << OriginalValue << ".0" << std::endl;
			return ;
		}
		case FLOAT :{
			double	IntPart;
			double OriginalValue = static_cast<double>(*(static_cast<float *>(MetamorphicData)));
			double FractPart = std::modf(OriginalValue, &IntPart);
			std::cout << OriginalValue;
			if (FractPart == 0.0)
				std::cout << ".0" << std::endl;
			else
				std::cout << std::endl;
			return ;
		}
		case DOUBLE :{
			double	IntPart;
			double OriginalValue = *(static_cast<double *>(MetamorphicData));
			double FractPart = std::modf(OriginalValue, &IntPart);
			std::cout << OriginalValue;
			if (FractPart == 0.0)
				std::cout << ".0" << std::endl;
			else
				std::cout << std::endl;
			return ;
		}
		case CHAR :{
			double	OriginalValue = static_cast<double>(*(static_cast<char *>(MetamorphicData)));
			std::cout << OriginalValue << ".0"<< std::endl;
			return ;
		}
		case FLOAT_SPE_CASE :{
			std::string tmp(static_cast<char *>(MetamorphicData));
			tmp.erase(tmp.size() - 1);
			std::cout << tmp << std::endl;
			return ;
		}
		case DOUBLE_SPE_CASE :{
			std::cout << static_cast<char *>(MetamorphicData) << std::endl;
			return ;	
		}
		default :
			std::cout << "Impossible" << std::endl;
			return ;
	}
}

void	ScalarConverter::freeMetamorphicData(void *MetamorphicData, int OriginType)
{
	switch (OriginType){
		case INT :
			delete static_cast<int *>(MetamorphicData);
			break ;
		case FLOAT :
			delete static_cast<float *>(MetamorphicData);
			break ;
		case DOUBLE :
			delete static_cast<double *>(MetamorphicData);
			break ;
		default :
			delete[] static_cast<char *>(MetamorphicData);
			break ;
	}
}
