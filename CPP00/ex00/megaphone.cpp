/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:25:34 by jduval            #+#    #+#             */
/*   Updated: 2023/07/18 13:04:50 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <iostream>

int	main(int ac, char **ag)
{
	if (ac == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	std::string output;
	for (int i = 1; ag[i] != NULL; i++){
		for (int j = 0; ag[i][j] != '\0'; j++)
			output.push_back(std::toupper(ag[i][j]));
	}
	std::cout << output << std::endl;
	return (0);
}
