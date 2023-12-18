/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:14:25 by ppotier           #+#    #+#             */
/*   Updated: 2023/12/01 16:32:05 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <string>

Span::Span(unsigned int size) : N(size) {};

template <typename T>
int	easyfind(T& type, int i)
{
	typename T::const_iterator it = std::find(type.begin(), type.end(), i);
	if (it == type.end())
		return (1);
	else
		return 	(0);
}

void	Span::addNumber(std::vector<int> &t_vec)
{
	if (t_vec.size() > (this->N - vec.size()))
		throw std::out_of_range("Too much elements");
	std::vector<int>::const_iterator it = t_vec.begin();
	std::vector<int>::const_iterator it2 = t_vec.end();
	vec.insert(vec.end(), it, it2);
}


void	Span::addNumber(int nb)
{
	if (this->vec.size() >= this->N)
		throw std::range_error("Cannot add numbers");
	else
	{
		if (easyfind(vec, nb) == 0)
			throw std::invalid_argument("Cannot add the same number");
		vec.push_back(nb);
	}
}

int		Span::longestSpan(void)
{
	int max;
	int min;
	if (this->vec.size() == 1)
		throw std::length_error("Vector size is too small");
	else if (this->vec.empty() == true)
		throw std::length_error("Vector is empty");
	else
	{
		max = *std::max_element(vec.begin(), vec.end());
		min = *std::min_element(vec.begin(), vec.end());
	}
	return (max - min);
}

Span &Span::operator=(const Span & rhs)
{
	if (this != &rhs)
	{
		this->N = rhs.N;
		this->vec = rhs.vec;
	}
	return *this;
}

int		Span::shortestSpan(void)
{
	if (this->vec.size() == 1)
		throw std::length_error("Vector size is too small");
	else if (this->vec.empty() == true)
		throw std::length_error("Vector is empty");
	int min = this->longestSpan();
	int shortest;
	std::vector<int> tmp = vec;
	std::sort(tmp.begin(), tmp.end());
	for (std::vector<int>::const_iterator it = tmp.begin(); it != tmp.end(); ++it)
	{
		for (std::vector<int>::const_iterator it2 = it; it2 != tmp.end(); ++it2)
		{
			if (*it == *it2)
				continue ;
			shortest = *it2 - *it;
			if (shortest < min)
				min = shortest;
		}
	}
	return min;
}
