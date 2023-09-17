/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:54:51 by jduval            #+#    #+#             */
/*   Updated: 2023/09/17 16:52:08 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <cstddef>

class ScalarConverter
{
		private :
			ScalarConverter();						//Default constructor
			ScalarConverter(ScalarConverter const &src);	//Copy constructor
			~ScalarConverter();						//Destructor
			ScalarConverter	&operator=(ScalarConverter const &rhs);

			static void		*firstConversion(int OriginType, std::string input);
			static void		freeMetamorphicData(void *MetamorphicData, int OriginType);
			static int		checkOverflow(int OriginType);
			static void		convertToChar(void *, int);
			static void		convertToInt(void *, int);
			static void		convertToFloat(void *, int);
			static void		convertToDouble(void *, int);

			static bool		_intOverflow;
			static bool		_floatOverflow;
			static bool		_doubleOverflow;

		public :

			static void	convert(std::string);
};

typedef void	MethodsPtr(void *data, int type);

#endif
