/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverte.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:43:11 by ppotier           #+#    #+#             */
/*   Updated: 2023/12/04 13:57:16 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverte.hpp"
#include <string>
#include <sstream>
#include <limits>
#include <iostream>

ScalarConverte::ScalarConverte(void) {};

ScalarConverte::~ScalarConverte(void) {};

ScalarConverte::ScalarConverte(const ScalarConverte& src)
{
	*this = src;
	return ;
}

ScalarConverte& ScalarConverte::operator=(const ScalarConverte &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const ScalarConverte& src)
{
    os << src;
    return os;
}


void ScalarConverte::convert(const char *input)
{
	double d;
	std::string str(input);

	std::stringstream res;
	res.precision(1); // 0.1
	res.setf(std::ios::fixed); // fixed notation

	if (str.length() == 1 && !std::isdigit(input[0])) {
		d = static_cast<double>(input[0]);
	}
	else {
		try {
			d = std::strtod(input, NULL);
		} catch (const std::invalid_argument& e){
			std::cerr << "Invalid number/Character" << std::endl;
			return ;
		} catch (const std::out_of_range &ofr) {
			ofr.what();
			return ;
		}
	}
	res << "double : " << d << std::endl;
	if (isinf(d) || isnan(d)) {
		res << "Int : Impossible" << std::endl;
	}
	else {
		int i = static_cast<int>(d);
		if (d > std::numeric_limits<int>::max() || d < -std::numeric_limits<int>::max()) {
			res << "Int : Out of Range" << std::endl;
	}
	else
		res << "int : " << i << std::endl;
	}
	if (isinf(d) || isnan(d)) {
		res << "Char : Impossible" << std::endl;
	}
	else {
		char c = static_cast<char>(d);
		if (c < 32 || c > 126)
			res << "char : Non displayable" << std::endl;
		else
			res << "char : '" << c << "'" << std::endl;
	}
	res << "float : " << static_cast<float>(d) << "f" << std::endl;
	std::cout << res.str();
	std::cout << "---------------------" << std::endl;
}