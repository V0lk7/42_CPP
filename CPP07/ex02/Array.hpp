/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:59:29 by jduval            #+#    #+#             */
/*   Updated: 2023/09/20 15:11:45 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array{

	private :
		T				*_array;
		unsigned int	_size;

	public :
		Array() : _size(0){
			this->_array = new T[this->_size];
		}

		Array(unsigned int n) : _size(n){
			this->_array = new T[this->_size];
		}

		~Array(){
			delete[] this->_array;
		}

		T	&operator[](unsigned int index){
			if (index >= this->_size)
				throw std::out_of_range("Value is out of range...");
			return (this->_array[index]);
		}

		Array	&operator=(Array &rhs){
			if (this->_array != NULL)
				delete[] this->_array;
			this->_size = rhs.size();
			this->_array = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = rhs[i];
			return (*this);
		}

		Array(Array &src){
			this->_array = NULL;
			*this = src;
		}

		unsigned int	size(void) const{
			return (this->_size);
		}
};

#endif
