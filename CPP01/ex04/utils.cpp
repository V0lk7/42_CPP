/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:47:30 by jduval            #+#    #+#             */
/*   Updated: 2023/07/25 16:57:00 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

void	create_name_outfile(std::string name, std::string &outfile)
{
	outfile = name;
	outfile += ".replace";
}
