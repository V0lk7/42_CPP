/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:54:51 by jduval            #+#    #+#             */
/*   Updated: 2023/08/03 17:00:58 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private	:
		int					_number;
		static const int	_nbr_of_bits;

	public	:
		Fixed();	//Default constructor
		~Fixed();	//Destructor
		Fixed(Fixed const &src);	//Copy constructor
		Fixed	&operator=(Fixed const &rhs); //overload operator -- rhs = Right Hand Side

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
