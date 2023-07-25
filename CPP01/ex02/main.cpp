/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:14:56 by jduval            #+#    #+#             */
/*   Updated: 2023/07/25 10:25:41 by jduval           ###   ########.fr       */
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
	std::cout << "Addresse of stringPTR = " << stringPTR << std::endl;
	std::cout << "Addresse of stringREF = " << &stringREF << std::endl;

	std::cout << "Value of variable = " << variable << std::endl;
	std::cout << "Value of stringPTR = " << *stringPTR << std::endl;
	std::cout << "Value of stringREF = " << stringREF << std::endl;
	return (0);
}
