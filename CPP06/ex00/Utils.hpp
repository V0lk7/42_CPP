/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:19:48 by jduval            #+#    #+#             */
/*   Updated: 2023/09/16 16:45:28 by jduval           ###   ########.fr       */
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

bool	CheckNumberOfArguments(int NumberOfArgs);
int		FindOriginType(std::string input);
void	*FirstConversion(int const OriginType, std::string input);
void	FreeMetamorphicData(void *Ptr, int const OriginType);

#endif
