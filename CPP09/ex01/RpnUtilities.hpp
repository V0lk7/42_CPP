/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RpnUtilities.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:17:28 by jduval            #+#    #+#             */
/*   Updated: 2023/10/01 18:55:52 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPNUTILITIES_HPP
# define RPNUTILITIES_HPP

# define ERROR 0
# define DIGIT 1
# define MINUS 2
# define PLUS 3
# define DIVIDE 4
# define MULTIPLY 5

# include <string>
# include <stack>

int		RecognizeInput(std::string UserInput);
void	AddDigitToStack(std::stack<double> &Numbers, std::string UserInput);
void	OperateOnStack(std::stack<double> &Numbers, int Type);

#endif
