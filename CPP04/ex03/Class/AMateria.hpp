/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:34:55 by jduval            #+#    #+#             */
/*   Updated: 2023/09/04 09:29:05 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

class ICharacter;

class AMateria
{
	protected	:
		std::string	const _type;
		AMateria	&operator=(AMateria const &rhs);
	
	public	:
		AMateria();
		AMateria(AMateria const &src);
		virtual	~AMateria();

		AMateria(std::string const &type);

		std::string const	&getType(void) const;

		virtual	AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target) const;
};

#endif
