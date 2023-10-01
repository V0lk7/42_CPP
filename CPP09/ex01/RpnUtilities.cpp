/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RpnUtilities.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:05:26 by jduval            #+#    #+#             */
/*   Updated: 2023/10/01 18:55:52 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RpnUtilities.hpp"
#include <cctype>
#include <cstdlib>
#include <stdexcept>

static int	IsSign(std::string UserInput);

int	RecognizeInput(std::string UserInput)
{
	if (UserInput.size() != 1)
		return (ERROR);
	if (isdigit(UserInput[0]) != 0)
		return (DIGIT);
	int	sign = IsSign(UserInput);
	if (sign != 0)
		return (sign);
	else
		return (ERROR);
}

void	AddDigitToStack(std::stack<double> &Numbers, std::string UserInput)
{
	double	Value = atof(UserInput.c_str());

	Numbers.push(Value);
	return ;
}

void	OperateOnStack(std::stack<double> &Numbers, int Type)
{
	if (Numbers.size() < 2)
		throw std::runtime_error("Can't do the operation without at least 2 elements");
	double a, b, result;

	a = Numbers.top();
	Numbers.pop();
	b = Numbers.top();
	Numbers.pop();
	if (Type == MINUS)
		result = b - a;
	else if (Type == PLUS)
		result = b + a;
	else if (Type == DIVIDE)
		result = b / a;
	else
		result = b * a;
	Numbers.push(result);	
}

static int	IsSign(std::string UserInput)
{
	char	c = UserInput[0];

	if (c == '-')
		return (MINUS);
	else if (c == '+')
		return (PLUS);
	else if (c == '/')
		return (DIVIDE);
	else if (c == '*')
		return (MULTIPLY);
	else
		return (0);
}
