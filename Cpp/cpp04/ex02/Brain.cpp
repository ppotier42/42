/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:25:17 by ppotier           #+#    #+#             */
/*   Updated: 2023/09/11 16:08:05 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
#include <string>

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
	for(int i = 0; i < 100; i++)
		this->ideas[i] = "";
	return ;
}

Brain::~Brain()
{
	std::cout << "Desctrutor called for Brain" << std::endl;
	return ;
}

Brain & Brain::operator=(Brain const & rhs)
{
	std::cout << "Brain assignement operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.getIdeas(i);
	}
	return (*this);
}

Brain::Brain(Brain const & src)
{
	std::cout << "Copy Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i].append(src.getIdeas(i));
	return ;
}

std::string Brain::getIdeas(int i) const
{
	return (this->ideas[i]);
}