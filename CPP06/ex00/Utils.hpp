/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:19:48 by jduval            #+#    #+#             */
/*   Updated: 2023/09/17 16:53:21 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <cstddef>
# include <string>

# define INT 0
# define CHAR 1
# define FLOAT 2
# define DOUBLE 3
# define FLOAT_SPE_CASE 10 
# define DOUBLE_SPE_CASE 11 

# define NBR_OF_TYPE 4
# define PARTICULAR_CASE_NBR 3
# define ERROR_TYPE 6

static char const	*RegParticularFloat[3] = {"^nanf$", "^-?inff$", "^\\+?inff$"};

static char const	*RegParticularDouble[3] = {"^nan$", "^-?inf$", "^\\+?inf$"};

static char const	*RegNormalCase[4] =	{"^-?[[:digit:]]+$", "^[[:graph:]]$",
										 "^-?[[:digit:]]+\\.[[:digit:]]+f$",
										 "^-?[[:digit:]]+\\.[[:digit:]]+$"};

static char const	*RegZero[2] = {"^-?0\\.0+f$", "^-?0\\.0+$"};

bool	CheckNumberOfArguments(int NumberOfArgs);
int		FindOriginType(std::string input);
int		CheckOverflow(void *MetamorphicData, int OriginType, std::string input);
bool	IsZero(std::string input, int OriginalType);


int		AsciiToInt(std::string input);
float	AsciiToFloat(std::string input);
double	AsciiToDouble(std::string input);

#endif
