/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:57:01 by jduval            #+#    #+#             */
/*   Updated: 2023/07/20 18:03:03 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_H
# define CONST_H

# include <string>

const std::string	bad_input[4] =
{	
	"Try to write something.",
	"Come on... It can't be empty, try again.",
	"Wrong command. Try this: ADD, SEARCH or EXIT",
	"Well done, you EOF the program... Now it's Exit time !"
};

const std::string	add_request[5] = 
{	
	"Enter the first name :",
	"Enter the last name :",
	"Enter the nickname :",
	"Enter the phone number :",
	"Enter the darkest secret :"
};

const int			contact_parameters = 5;
const int			number_of_contacts = 2;

#endif
