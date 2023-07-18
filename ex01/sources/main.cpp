/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:28:10 by jduval            #+#    #+#             */
/*   Updated: 2023/07/18 16:02:02 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	book;

	book.list[0].infos[0] = "hello";
	std::cout << book.list[0].infos[0] << std::endl;
	return (0);
}
