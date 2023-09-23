/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:57:11 by jduval            #+#    #+#             */
/*   Updated: 2023/09/23 12:38:22 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <iostream>

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
		int	result = abs(this->_span[0] - this->_span[1]);
		int	tmp;

		for (int i = 0; i < static_cast<int>(this->_spanNumbers) - 1; i++)
		{
			for (int j = i + 1; j < static_cast<int>(this->_spanNumbers); j++)
			{
				tmp = abs(this->_span[i] - this->_span[j]);
				if (result > tmp)
					result = tmp;
			}
		}
		return (result);
	}
}

int	Span::longestSpan(void)
{
	if (this->_span.size() < 2)
		throw (std::logic_error("Span : longestSpan : Need at least two value stored."));
	else {
		int	result = abs(this->_span[0] - this->_span[1]);
		int	tmp;

		for (int i = 0; i < static_cast<int>(this->_spanNumbers) - 1; i++)
		{
			for (int j = i + 1; j < static_cast<int>(this->_spanNumbers); j++)
			{
				tmp = abs(this->_span[i] - this->_span[j]);
				if (result < tmp)
					result = tmp;
			}
		}
		return (result);
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

void	Span::displaySpan(void)
{
	std::vector<int>::iterator	itBegin = this->_span.begin();
	std::vector<int>::iterator	itEnd = this->_span.end();
	while (itBegin != itEnd)
	{
		std::cout << *itBegin << " ";
		itBegin++;
	}
	std::cout << std::endl;
}
