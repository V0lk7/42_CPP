/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserMessages.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:01:44 by jduval            #+#    #+#             */
/*   Updated: 2023/10/07 14:30:12 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USERMESSAGES_HPP
# define USERMESSAGES_HPP

static const char	*ErrorNumbersOfArgs[3] = 
{
	"btc: Pathern: [./btc] [\"Input file\"].",
	"btc: Error: Need input file\n",
	"btc: Error: Too many arguments\n"
};

static const char	*ErrorOpeningFiles[2] =
{
	"btc: Open: Error occured during INPUT file opening, please make sure your file exist and it's readable.\n",
	"btc: Open: Error occured during DATA file opening, please verify that data.csv exist and it's readable.\n"
};

static const char	*ErrorParsingFile[8] =
{
	"btc: Wrong Header format in database file.\n", //0
	"btc: An error occurred during the reading of the DataFile.\n", //1
	"btc: There is no data in the file.\n", //2
	"btc: Error in creation of the data Regex.\n", //3
	"btc: Value is out of range.\n", //4
	"btc: Can't have the same date more than one.\n", //5
	"btc: Wrong Header format in input file.\n", //6
	"btc: An error occurred during the reading of the DataFile.\n" //7

};

#endif
