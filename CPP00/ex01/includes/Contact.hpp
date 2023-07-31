/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:22:47 by jduval            #+#    #+#             */
/*   Updated: 2023/07/31 09:22:03 by jduval           ###   ########.fr       */
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
		void 		set_infos(std::string[]);
		void		set_id(int);
		int			get_id() const;
		void		display_all_contacts() const;
		void		display_infos() const;
};

#endif
