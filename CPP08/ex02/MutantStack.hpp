/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:20:02 by jduval            #+#    #+#             */
/*   Updated: 2023/09/24 16:12:36 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public :
		MutantStack(){}
		~MutantStack(){}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin(){
			return (this->c.begin());
		}
		iterator	end(){
			return (this->c.end());
		}
};
