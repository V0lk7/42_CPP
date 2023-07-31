/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:41:28 by jduval            #+#    #+#             */
/*   Updated: 2023/07/31 16:21:18 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{
	private	:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public	:
		Harl();
		~Harl();
		void	complain(std::string);
};

#endif
