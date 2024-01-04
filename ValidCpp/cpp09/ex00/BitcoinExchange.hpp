/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:22:12 by ppotier           #+#    #+#             */
/*   Updated: 2023/12/20 11:19:01 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <map>
# include <string>
# include <iostream>

class Bitcoin {
	private :
		std::map<std::string, double> data;
		bool	checkData(const std::string &data);
		bool 	checkValue(const std::string &value);
		bool 	checkDate(const std::string &date);
		void	printFortune(const std::string &date, double value);
		Bitcoin() {};
	public :
	Bitcoin(const std::string &path);
	void checkInput(const std::string &Input);
	virtual ~Bitcoin() {};
};

#endif