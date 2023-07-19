/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:22:47 by jduval            #+#    #+#             */
/*   Updated: 2023/07/19 09:54:44 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private :
		std::string infos[5];
	public	:
		Contact();
		~Contact();
		int set_infos(std::string, int);
		int	get_infos(int);
};

#endif
