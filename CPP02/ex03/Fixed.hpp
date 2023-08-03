/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:54:51 by jduval            #+#    #+#             */
/*   Updated: 2023/08/03 17:01:21 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>

class Fixed
{
	private	:
		int					_number;
		static const int	_nbr_of_bits;

	public	:
		Fixed();					//Default constructor
		Fixed(Fixed const &src);	//Copy constructor
		~Fixed();					//Destructor
		Fixed(int const value);
		Fixed(float const value);

		bool	operator>(Fixed const &rhs) const;
		bool	operator>=(Fixed const &rhs) const;
		bool	operator<(Fixed const &rhs) const;
		bool	operator<=(Fixed const &rhs) const;
		bool	operator==(Fixed const &rhs) const;
		bool	operator!=(Fixed const &rhs) const;
		Fixed	&operator=(Fixed const &rhs);
		Fixed	operator+(Fixed const &rhs) const;
		Fixed	operator-(Fixed const &rhs) const;
		Fixed	operator*(Fixed const &rhs) const;
		Fixed	operator/(Fixed const &rhs) const;
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed		&min(Fixed &lhs, Fixed &rhs);
		static Fixed		&max(Fixed &lhs, Fixed &rhs);
		static Fixed const	&min(Fixed const &lhs, Fixed const &rhs);
		static Fixed const	&max(Fixed const &lhs, Fixed const &rhs);

};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);

#endif
