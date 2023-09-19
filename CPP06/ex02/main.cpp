/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:51:08 by jduval            #+#    #+#             */
/*   Updated: 2023/09/19 12:57:12 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Base.hpp>
#include <iostream>
#include <cstdlib>

Base	*generate(void)
{
	int	RandomNumber = rand() % 3;

	switch(RandomNumber){
		case 0 :{
			Base	*ptr = new A();
			return (ptr);
		}
		case 1 :{
			Base	*ptr = new B();
			return (ptr);
		}
		default :{
			Base	*ptr = new C();
			return (ptr);
		}
	}
	return (NULL);
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "Class is A type" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "Class is B type" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "Class is C type" << std::endl;
	else
		std::cout << "Well, unknow type..." << std::endl;
}

void	identify(Base &p)
{
	try{
		A	&result = dynamic_cast<A &>(p);
		(void)result;
		std::cout << "Class is A type" << std::endl;
	}
	catch (std::exception &e){
		try{
			B	&result = dynamic_cast<B &>(p);
			(void)result;
			std::cout << "Class is B type" << std::endl;
		}
		catch (std::exception &e){
			try{
				C	&result = dynamic_cast<C &>(p);
				(void)result;
				std::cout << "Class is C type" << std::endl;
			}
			catch (std::exception &e){
				std::cerr << "Well, unknow type..." << std::endl;
			}
		}
	}
}

int	main(void)
{
	srand(time(NULL));
	std::cout << "=========================================" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		Base	*ptr = generate();
		identify(ptr);
		delete ptr;
	}
	std::cout << "=========================================" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		Base	*ptr1 = generate();
		identify(*ptr1);
		delete ptr1;
	}
	std::cout << "=========================================" << std::endl;
	return (0);
}
