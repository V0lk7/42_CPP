/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:55:40 by jduval            #+#    #+#             */
/*   Updated: 2023/07/27 10:20:59 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

# include <string>

# define INFILE 0
# define OUTFILE 3

//file : parse_inputs.cpp
bool	input_is_valid(int ac, char **av, std::string (&inputs)[4]);

//file : utils.cpp
void	create_name_outfile(std::string name, std::string &outfile);

//file : file_access.cpp
bool	files_are_valid(std::ifstream &infile,
						std::ofstream &outfile,
						std::string (&inputs)[4]);

//file : change_input.cpp
int		change_input(std::ifstream &infile,
					std::ofstream &outfile,
					std::string (&inputs)[4]);
#endif
