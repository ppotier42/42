/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:00:28 by ppotier           #+#    #+#             */
/*   Updated: 2023/12/01 16:33:31 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
# include <iostream>
# include <algorithm>
# include <vector>
# include <string>

// easyfind pour eter sur qu'il ne remet pas plusieurs elements;

class Span {
	private :
	unsigned int N;
	std::vector<int> vec;
	public :
	// Span(void) {};
	Span(unsigned int size);
	~Span(void) {};
	void	addNumber(int nb);
	void	addNumber(std::vector<int> &t_vec);
	int		shortestSpan(void);
	int		longestSpan(void);
	Span &operator=(const Span &rhs);
};

#endif