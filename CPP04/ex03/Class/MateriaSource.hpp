/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:25:50 by jduval            #+#    #+#             */
/*   Updated: 2023/09/04 14:54:54 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"


class MateriaSource : public IMateriaSource
{
	private	:
		AMateria	*_stock[4];
		int			_count;

	public	:
		MateriaSource();
		MateriaSource(MateriaSource const &);
		virtual	~MateriaSource();
		MateriaSource	&operator=(MateriaSource const &);

		virtual void		learnMateria(AMateria *);
		virtual AMateria	*createMateria(std::string const &type);

		AMateria			*getMateria(int index) const;
		int					getCount(void) const;
};

#endif
