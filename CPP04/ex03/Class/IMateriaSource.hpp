/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:05:22 by jduval            #+#    #+#             */
/*   Updated: 2023/08/10 11:26:31 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <string>

class AMateria;

class IMateriaSource
{
	public	:
		IMateriaSource();
		IMateriaSource(IMateriaSource const &);
		virtual	~IMateriaSource();
		IMateriaSource	&operator=(IMateriaSource const &);

		virtual void		learnMateria(AMateria *) = 0;
		virtual AMateria	*createMateria(std::string const &type) = 0;
};

#endif
