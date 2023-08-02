/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:54:51 by jduval            #+#    #+#             */
/*   Updated: 2023/08/01 16:30:02 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private	:
		int					_number;
		static const int	_nbr_of_bits;

	public	:
		Fixed();	//Default constructor
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const &src);	//Copy constructor
		~Fixed();	//Destructor
		Fixed	&operator=(Fixed const &rhs); //overload operator -- rhs = Right Hand Side

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);

#endif
