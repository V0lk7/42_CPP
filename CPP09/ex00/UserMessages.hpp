/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserMessages.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:01:44 by jduval            #+#    #+#             */
/*   Updated: 2023/09/26 15:12:34 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERMESSAGES_HPP
# define USERMESSAGES_HPP

#include <string>

static const std::string	ErrorNumbersOfArgs[3] = 
{
	"btc: Pathern: [./btc] [\"Input file\"].",
	"btc: Error: Need input file\n",
	"btc: Error: Too many arguments\n"
};

static const std::string	ErrorOpeningFiles[2] =
{
	"btc: Open: Error occured during INPUT file opening, please make sure your file exist and it's readable.\n",
	"btc: Open: Error occured during DATA file opening, please verify that data.csv exist and it's readable.\n"
};

#endif
