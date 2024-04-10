/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:11:12 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/21 17:18:09 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string str("HI THIS IS BRAIN");
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	
	std::cout << "Adresse memoire : " << &stringPTR << std::endl;
	std::cout << "Adresse stocké : " << stringPTR << std::endl;
	std::cout << "Addresee stocké REF : " << &stringREF << std::endl;

	std::cout << "str : " << str << std::endl;
	std::cout << "PTR : " << *stringPTR << std::endl;
	std::cout << "REF : " << stringREF << std::endl;
	return 0;
}