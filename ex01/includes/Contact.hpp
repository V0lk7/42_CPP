/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:22:47 by jduval            #+#    #+#             */
/*   Updated: 2023/07/20 17:22:08 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include "utils.hpp"

class Contact
{
	private :
		std::string infos[contact_parameters];
		int	id;
	public	:
		Contact();
		~Contact();
		void 		set_infos(std::string, int);
		std::string	get_infos(int);
		void		set_id(int);
		int			get_id();
		void		debug_display();
};

#endif
