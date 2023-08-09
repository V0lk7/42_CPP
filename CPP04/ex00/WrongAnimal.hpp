/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:54:51 by jduval            #+#    #+#             */
/*   Updated: 2023/08/08 15:40:21 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal
{
	protected	:

		std::string		_type;

	public	:

		WrongAnimal();					//Default constructor
		WrongAnimal(WrongAnimal const &src);	//Copy constructor
		~WrongAnimal();					//Destructor
		WrongAnimal	&operator=(WrongAnimal const &rhs);

		WrongAnimal(std::string const);

		std::string		getType(void) const;
		void			makeSound(void) const;
};

#endif
