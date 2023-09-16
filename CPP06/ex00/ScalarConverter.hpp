/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:54:51 by jduval            #+#    #+#             */
/*   Updated: 2023/09/16 16:45:29 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter
{
		private :
			ScalarConverter();						//Default constructor
			ScalarConverter(ScalarConverter const &src);	//Copy constructor
			~ScalarConverter();						//Destructor
			ScalarConverter	&operator=(ScalarConverter const &rhs);

//			static void		ConvertToChar(void *, int);
//			static void		ConvertToInt(void *, int);
//			static void		ConvertToFloat(void *, int);
//			static void		ConvertToDouble(void *, int);

		public :

			static void	convert(std::string);
};

#endif
