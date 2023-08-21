/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:49:58 by jduval            #+#    #+#             */
/*   Updated: 2023/08/21 13:21:32 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
	protected	:
		std::string	ideas[100];

	public	:
		Brain();					//Default constructor
		Brain(Brain const &src);	//Copy constructor
		~Brain();					//Destructor
		Brain	&operator=(Brain const &rhs);

		void				setBrainIdea(int const, std::string const);
		std::string const	getBrainIdea(int const) const;
};

#endif
