/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:25:50 by jduval            #+#    #+#             */
/*   Updated: 2023/08/21 08:40:40 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>

class AMateria;

class MateriaSource : public IMateriaSource
{
	private	:
		AMateria	*_stock[4];
		size_t		_count;
	public	:
		MateriaSource();
		MateriaSource(IMateriaSource const &);
		virtual	~MateriaSource();
		MateriaSource	&operator=(IMateriaSource const &);

		virtual void		learnMateria(AMateria *);
		virtual AMateria	*createMateria(std::string const &type);
};

#endif
