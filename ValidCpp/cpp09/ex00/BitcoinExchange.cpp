/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:22:44 by ppotier           #+#    #+#             */
/*   Updated: 2023/12/19 14:20:02 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <map>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

Bitcoin::Bitcoin(const std::string &path)
{
	std::fstream	file(path.c_str());
	std::string		line;
	std::size_t		separator;
	double			value;
	std::string		date;
	std::string		val;

	if (!file.is_open()) {
		std::cerr << "Error: Could not open file\n";
		return ;
	}
	else if (file.is_open())
	{
		getline(file, line);
		while(std::getline(file, line))
		{
			separator = line.find(",");
			if (separator == std::string::npos)
			{
				std::cerr << "Error: Not the right format" << std::endl;
				std::cerr << line << "\n";
				continue ;
			}
			date = line.substr(0, separator);
			val = line.substr(separator + 1);
			separator = val.find(",");
			if (separator != std::string::npos)
			{
				std::cerr << "Error: Not the right format" << std::endl;
				std::cerr << line << "\n";
				continue ;
			}
			std::stringstream(val) >> value;
			data[date] = value;
		}
		file.close();
	}
}

bool	Bitcoin::checkData(const std::string &data)
{
	if (data.length() < 14)
	{
		std::cerr << "Error: Not the right format => " << data << std::endl;
		return (false);
	}
	else if (!data.find_first_not_of("0123456789. |-"))
	{
		std::cerr << "Error: Invalid Character => " << data << std::endl;
		return (false);
	}
	else if (std::count(data.begin(), data.end(), ' ') != 2)
	{
		std::cerr << "Error: not the right space(s) number => " << data << std::endl;
		return (false);
	}
	else if (std::count(data.begin(), data.end(), '|') != 1 ||
		std::count(data.begin(), data.end(), '-') != 2)
	{
		std::cerr << "Error: not the right delimiters(s) number => " << data << std::endl;
		return (false);
	}
	// maybe too much ?
	// else if (data.substr(10, 3) != " | ") 
	// {
	// 	std::cout << "'|' is not at the right place" << data << std::endl;
	// 	return (false);
	// }
	return (true);
}

bool Bitcoin::checkValue(const std::string &value)
{
	float num;
	if (value.find('-') != std::string::npos) {
		std::cerr << "Error: Not a positive number => " << value << std::endl;
		return (false);
	}
	else if (value.find_first_of("| -") != std::string::npos) {
		std::cerr << "Error: Invalid Format " << num << std::endl;
		return (false);
	}
	if (value.size() > 4 && value.find(".") >= 4) {
		std::cerr << "Error: too large number " << value << std::endl;
		return (false);
	}
	std::stringstream(value) >> num;
	if (num > static_cast<float>(1000)) {
		std::cerr << "Error: too large number " << value << std::endl;
		return (false);
	}
	return (true);
}

bool	Bitcoin::checkDate(const std::string &date)
{
	int	year, month, day;
	char	separator;
	
	std::istringstream ss(date);
	ss >> year >> separator >> month >> separator >> day;
	if (year < 2009 || year > 2022) {
		std::cerr << "Error : No data registered" << std::endl;
		return (false);
	}
	else if (year >= 2022 && month >= 3 && day > 29) {
		std::cerr << "Error: Data limit found" << std::endl;
		return (false);
	}
	// par 4 mais pas par 100, ou bien si elle est divisible par 400.
	else if (month == 2 && day > 28) {
		if (year % 4 != 0 || year % 100 == 0 || year % 400 == 0) {
			std::cerr << "Error: Not a leap year" << std::endl;
		return (false);
		}
	}
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30) {
			std::cerr << "Error: Not a month with 31 days" << std::endl;
			return (false);
		}
	}
	return (true);
}

void	Bitcoin::printFortune(const std::string &date, double value)
{
	std::map<std::string, double>::iterator it = data.lower_bound(date);
	double finalValue;

	if (it != data.end()) {
		if (it->first != date)
			--it;
		finalValue = (it->second);
	}
	else if (!data.empty()) {
		finalValue = ((--it)->second);
	}
	else {
		std::cerr << "Error: No changes rate found for => " << date << std::endl;
		return ;
	}
	std::cout << date << " => " << value << " = " << value * finalValue << std::endl;
}


void Bitcoin::checkInput(const std::string &Input)
{
	std::fstream	file(Input.c_str());
	double			doubleValue;
	std::string		date;
	std::string		value;
	std::string		line;

	if (!file.is_open())
	{
		std::cerr << "Error: Cannot open file" << std::endl;
		return ;
	}
	if (file.is_open())
	{
		getline(file, line);
		if (line != "date | value"){
			std::cerr << "Error: First line input not correct\n";
			return ;
		}
	}
	while(getline(file, line))
	{
		if (this->checkData(line) == false)
			continue ;
		date = line.substr(0, 10);
		value = line.substr(13);
		if (this->checkValue(value) == false)
			continue ;
		if (this->checkDate(date) == false)
			continue ;
		std::stringstream(value) >> doubleValue;
		this->printFortune(date, doubleValue);
	}
	file.close();
	return ;
}

