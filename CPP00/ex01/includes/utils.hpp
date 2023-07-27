/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:57:01 by jduval            #+#    #+#             */
/*   Updated: 2023/07/27 15:58:21 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_H
# define CONST_H

# include <string>

const std::string	bad_input[5] =
{	
	"Try to write something.",
	"Come on... It can't be empty, try again.",
	"Wrong command. Try this: ADD, SEARCH or EXIT",
	"Well done, you EOF the program... Now it's Exit time !",
	"Problem in your input. Try again. Put an id between 0 and "
};

const std::string	add_request[6] = 
{	
	"Enter the first name :",
	"Enter the last name :",
	"Enter the nickname :",
	"Enter the phone number :",
	"Enter the darkest secret :",
	"The contact is not completely set. All modification will be lost.\nReturn to the main menu."
};

const std::string	search_request[3] =
{
	"Enter the ID of the contact wanted :",
	"No contact set. Try ADD to set at least one contact",
	"Not a valid ID. Try a valid id between 0 and "
};

const std::string	contact_params[5] = 
{
	"First name : ",
	"Last name : ",
	"Nickname : ",
	"Phone number : ",
	"Darkest secret : "
};

const std::string	user_pathern[5] = 
{
	"ADD",
	"SEARCH",
	"EXIT",
	"RETURN",
	"Return to the main menu."
};

const int			contact_parameters = 5;
const int			number_of_contacts = 8;
const int			width_col = 10;

#endif
