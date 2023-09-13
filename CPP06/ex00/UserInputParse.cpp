/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserInputParse.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:11:27 by jduval            #+#    #+#             */
/*   Updated: 2023/09/13 14:14:36 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

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
