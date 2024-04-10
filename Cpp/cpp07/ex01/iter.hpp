/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:08:37 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/30 12:59:44 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void	iter(T *array, size_t const lenght, void f(T&)){
	for (int i = 0; i < lenght; i++)
		f(array[i]); 
	return;
};

#endif