/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 08:36:27 by jduval            #+#    #+#             */
/*   Updated: 2023/09/23 12:38:20 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

int	main(void)
{
	{
		Span	test(5);
		
		test.fillSpan();
		test.displaySpan();
		std::cout << "Shortest span : " << test.shortestSpan() << std::endl;
		std::cout << "Longest span : " << test.longestSpan() << std::endl;
	}
	{
		try{
			Span	test(2);

			test.addNumber(10);
			test.shortestSpan();
		}
		catch(std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	{
		try{
			Span	test(2);

			test.addNumber(10);
			test.longestSpan();
		}
		catch(std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	{
		try{
			Span	test(2);

			test.addNumber(10);
			test.addNumber(10);
			test.addNumber(10);
		}
		catch(std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
