/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:22:40 by ppotier           #+#    #+#             */
/*   Updated: 2023/12/19 14:23:03 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <string>

class RPN {
	private :
		std::stack<double> numbers;
	public :
		RPN() {};
		RPN(std::stack<double> number);
		RPN(std::string &Input) {};
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);
		~RPN() {};
		void	doOperation(std::string &Input);
};

#endif