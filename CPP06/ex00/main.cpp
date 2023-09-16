/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:03:32 by jduval            #+#    #+#             */
/*   Updated: 2023/09/16 16:45:27 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Utils.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (CheckNumberOfArguments(argc) != true)
		return (1);
	int const	OriginType = FindOriginType(static_cast<char *>(argv[1]));
	void	*MetamorphicData = FirstConversion(OriginType, argv[1]);

	std::cout << OriginType << std::endl;
	FreeMetamorphicData(MetamorphicData, OriginType);
//	ScalarConverter::convert(argv[1]);
	return (0);
}
