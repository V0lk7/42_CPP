/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:54:51 by jduval            #+#    #+#             */
/*   Updated: 2023/09/19 16:25:33 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>

struct Data;

class Serializer
{
		private :
			Serializer();						//Default constructor
			Serializer(Serializer const &src);	//Copy constructor
			~Serializer();						//Destructor
			Serializer	&operator=(Serializer const &rhs);

		public :
			static uintptr_t		serialize(Data *ptr);
			static Data				*deserialize(uintptr_t raw);
};

struct Data
{
	int		a;
	char	b;
};

#endif
