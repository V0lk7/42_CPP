/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:03:32 by jduval            #+#    #+#             */
/*   Updated: 2023/09/17 16:53:29 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Utils.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (CheckNumberOfArguments(argc) != true)
		return (1);
	ScalarConverter::convert(argv[1]);
	return (0);
}
