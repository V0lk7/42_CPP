/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:14:56 by jduval            #+#    #+#             */
/*   Updated: 2023/07/31 09:50:27 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	variable = "HI THIS IS BRAIN";
	std::string	*stringPTR = &variable;
	std::string	&stringREF = variable;

	std::cout << "Addresse of variable = " << &variable << std::endl;
	std::cout << "Addresse stocked in stringPTR = " << stringPTR << std::endl;
	std::cout << "Addresse stocked in stringREF = " << &stringREF << std::endl;

	std::cout << "Value of variable = " << variable << std::endl;
	std::cout << "Value pointed by stringPTR = " << *stringPTR << std::endl;
	std::cout << "Value pointed by stringREF = " << stringREF << std::endl;
	return (0);
}
