/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:06:45 by jduval            #+#    #+#             */
/*   Updated: 2023/07/25 17:24:55 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

int	main(void)
{
	std::fstream	file;
	try{
		file.open("test");
	}catch (std::ios_base::failure	&fail){
		std::cerr	<< fail.what() << std::endl;
	}
	if (file.is_open() == false)
		std::cout << "mdr" << std::endl;
	return (0);
}
