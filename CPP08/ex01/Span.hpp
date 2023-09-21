/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:51:50 by jduval            #+#    #+#             */
/*   Updated: 2023/09/21 16:08:03 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span
{
	private :
		std::vector<int>	_span;
		unsigned int		_spanNumbers;

		Span();
		std::vector<int>::iterator	getBeginIterator(void) const;
		std::vector<int>::iterator	getEndIterator(void) const;
		unsigned int				getSpanNumbers(void) const;

	public :
		Span(unsigned int n);
		Span(Span const &src);
		~Span();
		Span	&operator=(Span const &src);

		void	addNumber(int);
		int		shortestSpan(void);
		int		longestSpan(void);
		void	fillSpan(void);
		void	displaySpan(void) const;
};

#endif
