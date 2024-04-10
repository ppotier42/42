/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:25:17 by ppotier           #+#    #+#             */
/*   Updated: 2023/12/20 11:13:34 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <limits.h>

RPN::RPN(std::stack<double> number)
{
	this->numbers = number;
}

RPN::RPN(const RPN &src)
{
	*this = src;
}

RPN &RPN::operator=(const RPN &src)
{
	this->numbers = src.numbers;
	return (*this);
}

void	RPN::doOperation(std::string &Input)
{
	for (size_t i = 0; i < Input.size(); i++) {
		char c = Input[i];
		if (c == ' ')
			continue ;
		else if (isdigit(c))
		{
			int nb = c - '0';
			numbers.push(nb);
		}
		else if (c == '-' && numbers.size() >= 2)
		{
			double a = numbers.top();
			numbers.pop();
			double b = numbers.top();
			numbers.pop();
			numbers.push(b - a);
		}
		else if (c == '+' && numbers.size() >= 2)
		{
			double a = numbers.top();
			numbers.pop();
			double b = numbers.top();
			numbers.pop();
			numbers.push(b + a);
		}
		else if (c == '*' && numbers.size() >= 2)
		{
			double a = numbers.top();
			numbers.pop();
			double b = numbers.top();
			numbers.pop();
			numbers.push(b * a);
		}
		else if (c == '/' && numbers.size() >= 2)
		{
			double a = numbers.top();
			numbers.pop();
			double b = numbers.top();
			numbers.pop();
			numbers.push(b / a);
		}
		else {
			std::cerr << "Error" << std::endl;
			return ;
		}
	}
	if (numbers.size() == 1)
		std::cout << numbers.top() << std::endl;
	else
		std::cerr << "Error" << std::endl;
}