/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:34:09 by jduval            #+#    #+#             */
/*   Updated: 2023/09/06 11:40:38 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
	{
		try{
			std::cout << "Create Bureaucrate with grade = 160" << std::endl;
			Bureaucrat	employe1("Joe", 160);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try{
			std::cout << "Create Bureaucrate with grade = -250" << std::endl;
			Bureaucrat	employe1("Joe", -250);
		}
		catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	{
		Bureaucrat	employe2("Joe", 45);
		Bureaucrat	employe3("Marine", 67);
		std::cout << employe2 << std::endl;
		std::cout << employe3 << std::endl;
		employe2.IncrementGrade();
		employe3.DecrementGrade();
		std::cout << employe2 << std::endl;
		std::cout << employe3 << std::endl;
		employe2 = employe3;
		std::cout << employe2 << std::endl;
		std::cout << employe3 << std::endl;
	}
	{
		try {
			Bureaucrat	employe4("Marty", 150);
			employe4.DecrementGrade();
		}
		catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
