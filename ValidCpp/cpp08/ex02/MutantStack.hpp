/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:29:33 by ppotier           #+#    #+#             */
/*   Updated: 2023/12/01 17:49:57 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public :
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	MutantStack () : std::stack<T, Container>() {};
	MutantStack(const MutantStack<T, Container>& other) : std::stack<T, Container>(other) {};
	
	~MutantStack() {};

	MutantStack<T, Container>&operator=(const MutantStack<T, Container> & rhs)
	{
		*this = rhs;
		return *this;
	}
	
	iterator begin() {return std::stack<T, Container>::c.begin();};
	iterator end() {return std::stack<T, Container>::c.end();};

	const iterator begin() const {return std::stack<T, Container>::c.begin();};
	const iterator end() const {return std::stack<T, Container>::c.end();};
};

#endif