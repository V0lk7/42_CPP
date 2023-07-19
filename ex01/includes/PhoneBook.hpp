/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:13:57 by jduval            #+#    #+#             */
/*   Updated: 2023/07/19 18:57:38 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private :
		Contact list[8];
		int		index;
	public	:
		PhoneBook();
		~PhoneBook();
		int		get_index();
		void	increment_index();
		Contact	&get_contact(int);
};

#endif
