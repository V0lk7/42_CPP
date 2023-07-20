/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:13:57 by jduval            #+#    #+#             */
/*   Updated: 2023/07/20 17:38:44 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "utils.hpp"

class PhoneBook
{
	private :
		Contact list[number_of_contacts];
		int		index;
	public	:
		PhoneBook();
		~PhoneBook();
		int		get_index();
		void	increment_index(int i = 1);
		Contact	&get_contact(int);
};

#endif
