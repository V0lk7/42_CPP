/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:54:51 by jduval            #+#    #+#             */
/*   Updated: 2023/07/31 14:05:43 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private	:
		int					number;
		static const int	nbr_of_bits;

	public	:
		Fixed();	//Default constructor
		~Fixed();	//Destructor
		Fixed(Fixed const &src);	//Copy constructor
		Fixed	&operator=(Fixed const &rhs); //overload operator -- rhs = Right Hand Side

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
