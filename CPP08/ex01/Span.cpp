/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:57:11 by jduval            #+#    #+#             */
/*   Updated: 2023/09/21 16:08:04 by jduval           ###   ########.fr       */
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

Span	&Span::operator=(Span const &src)
{
	this->_spanNumbers = src.getSpanNumbers();
	if (this->_span.size() > 0)
		this->_span.erase(this->_span.begin(), this->_span.end());
	std::copy(src.getBeginIterator(), src.getEndIterator(), this->_span.begin());
	return (*this);
}

unsigned int	Span::getSpanNumbers(void) const
{
	return (this->_spanNumbers);
}

std::vector<int>::iterator	Span::getBeginIterator(void) const
{
	return (this->_span.begin());
}

std::vector<int>::iterator	Span::getEndIterator(void) const
{
	return (this->_span.end());
}

void	Span::addNumber(int number)
{
	if (this->_span.size() == this->_spanNumbers)
		throw (std::logic_error("Span : AddNumbers Errors : Can't store number anymore.");
	else
		this->_span.push_back(number);
}

int	Span::shortestSpan(void)
{
	if (this->_span.size() < 2)
		throw (std::logic_error("Span : shortestSpan : Need at least two value stored."));
	else {
		int	result = abs(this->_span[i] - this->_span[j]);

		for (int i = 0; i < static_cast<int>this->_spanNumbers - 1; i++)
		{
			for (int j = i + 1; j < static_cast<int>this->_spanNumbers; j++)
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
		int	result = abs(this->_span[i] - this->_span[j]);

		for (int i = 0; i < static_cast<int>this->_spanNumbers - 1; i++)
		{
			for (int j = i + 1; j < static_cast<int>this->_spanNumbers; j++)
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
	std::generate(this->_span.begin(), this->_span.end(), rand());
}

void	Span::displaySpan(void) const
{
	for (std::vector<int>::iterator it = this->getBeginIterator(); it < this->getEndIterator(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}
