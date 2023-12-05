/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:09:02 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/30 13:05:24 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"
#include <string>

template <typename T>
void print(T &i)
{
	std::cout << i << std::endl;
	return ;
}

template <typename T>
void add(T &i)
{
	i += 3;
	return ;
}

int main(void)
{
	int array[10];
	for (int i = 0; i < 10; i++)
		array[i] = i;
	iter(array, 3, add);
	iter(array, 5, print);
	char str[10];
	for (int i = 0; i < 10; i++)
		str[i] = 'a';
	iter(str, 3, add);
	iter(str, 5, print);
	return 0;
}