/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:59:34 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/31 12:32:04 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

std::string	get_char_from_file(std::ifstream & filein)
{
	std::string res("");
	char c = filein.get();

	while(filein.good())
	{
		res += c;
		c = filein.get();
	}
	return (res);
}

std::string search_and_replace(std::string const &filedata, std::string const &oldStr, std::string const &newStr)
{
	std::string res("");
	int	lenOld(oldStr.length());
	int	len(filedata.length());
	int i = 0;
	while (i < len)
	{
		if (filedata.substr(i, lenOld) == oldStr)
		{	
			res.append(newStr);
			i += lenOld;
		}
		else
		{
			res += filedata[i];
			i++;
		}
	}
	return (res);
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}
	std::string		filename(av[1]);
	std::string		filecpy(filename);
	filecpy.append(".replace");
	
	std::ifstream	file_in(filename);
	std::string		filedata;
	if (!file_in.good())
	{
		std::cout << "Cannot open file" << std::endl;
		return (1);
	}
	filedata = get_char_from_file(file_in);
	file_in.close();

	std::string	oldStr(av[2]);
	std::string	newStr(av[3]);
	std::string	tmp;

	tmp = search_and_replace(filedata, oldStr, newStr);

	std::ofstream	file_out(filecpy);
	file_out << tmp;
	file_out.close();
	return (0);
}