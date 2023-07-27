/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:54:51 by jduval            #+#    #+#             */
/*   Updated: 2023/07/27 15:26:11 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private	:
		const int			number;
		static const int	nbr_of_bits;

	public	:
		Fixed();				//Default constructor
		~Fixed();				//Destructor
		Fixed(const Fixed &);	//Copy constructor
		Fixed	&operator=(const Fixed &); //overload operator

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
}

#endif
