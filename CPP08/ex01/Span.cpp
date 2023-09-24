/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:57:11 by jduval            #+#    #+#             */
/*   Updated: 2023/09/24 14:21:49 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <iostream>
#include <algorithm>

Span::Span(){}

Span::Span(unsigned int n) : _spanNumbers(n) {}

Span::Span(Span const &src) :  _spanNumbers(src.getSpanNumbers())
{
	*this = src;
}

Span::~Span(){}

Span	&Span::operator=(Span const &src)
{
	this->_spanNumbers = src.getSpanNumbers();
	if (this->_span.size() > 0)
		this->_span.erase(this->_span.begin(), this->_span.end());
	std::copy(src._span.begin(), src._span.end(), this->_span.begin());
	return (*this);
}

unsigned int	Span::getSpanNumbers(void) const
{
	return (this->_spanNumbers);
}

void	Span::addNumber(int number)
{
	if (this->_span.size() == this->_spanNumbers)
		throw (std::logic_error("Span : addNumbers : Can't store any more numbers."));
	else
		this->_span.push_back(number);
}

int	Span::shortestSpan(void)
{
	if (this->_span.size() < 2)
		throw (std::logic_error("Span : shortestSpan : Need at least two value stored."));
	else {
		sort(this->_span.begin(), this->_span.end());

		std::vector<int>::iterator	itFirst = this->_span.begin();
		std::vector<int>::iterator	itSecond = itFirst + 1;
		int	result = abs((*itFirst) - (*itSecond));
		int	tmp;
		while (itSecond != this->_span.end())
		{
			tmp = abs((*itFirst) - (*itSecond));
			if (result > tmp)
				result = tmp;
			itFirst++;
			itSecond++;
		}
		return (result);
	}
}

int	Span::longestSpan(void)
{
	if (this->_span.size() < 2)
		throw (std::logic_error("Span : longestSpan : Need at least two value stored."));
	else {
		sort(this->_span.begin(), this->_span.end());
		
		std::vector<int>::iterator	itBegin = this->_span.begin();
		std::vector<int>::iterator	itEnd = this->_span.end() - 1;

		return ((*itEnd) - (*itBegin));
	}
}

void	Span::fillSpan(void)
{
	srand(time(NULL));

	this->_span.erase(this->_span.begin(), this->_span.end());
	this->_span.insert(this->_span.begin(), this->_spanNumbers, 0);
	for (unsigned int i = 0; i < this->_spanNumbers; i++)
		this->_span[i] = rand() % (this->_spanNumbers * 2);
}

static void	prinToScreen(int value)
{
	std::cout << ' ' << value;
}

void	Span::displaySpan(void)
{
	std::cout << "My vector contain :";
	for_each(this->_span.begin(), this->_span.end(), prinToScreen);
	std::cout << std::endl;
}
