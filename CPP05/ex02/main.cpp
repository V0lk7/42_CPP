/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:34:09 by jduval            #+#    #+#             */
/*   Updated: 2023/09/06 14:13:36 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

static void	TestFormClass(void)
{
	{
		std::cout << "Simple test of Form class\n" << std::endl;
	}
	{
		std::cout << "TEST1 : gradetoexecute < 1" << std::endl;
		try{
			Form	document1("home", 50, 0);
		}
		catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "TEST2 : gradetoexecute > 150" << std::endl;
		try{
			Form	document1("home", 50, 151);
		}
		catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "TEST3 : gradeToSign > 150" << std::endl;
		try{
			Form	document1("home", 151, 45);
		}
		catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "TEST4 : gradeToSign < 1" << std::endl;
		try{
			Form	document1("home", 0, 45);
		}
		catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "TEST5 : copy constructor" << std::endl;
		Form	document1("home", 50, 50);
		Form	document2(document1);
		std::cout << "Document1 : " << &document1 << "\n" << document1 << std::endl;
		std::cout << "Document2 : " << &document2 << "\n" << document2 << std::endl;
	}
}

static void	TestSignForm(void)
{
	{
		std::cout << "Test Sign Form" << std::endl;
	}
	{
		std::cout << "Test with failure" << std::endl;
		Form	doc1("A", 14, 1);
		std::cout << doc1 << std::endl;
		Bureaucrat	employe("Joe", 15);
		employe.signForm(doc1);
		std::cout << "Test with success" << std::endl;
		employe.IncrementGrade();
		employe.signForm(doc1);
		std::cout << doc1 << std::endl;
	}
}

int	main(void)
{
	TestFormClass();
	TestSignForm();
	
	return (0);
}
