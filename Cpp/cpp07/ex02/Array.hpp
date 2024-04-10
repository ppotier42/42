/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:48:52 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/30 16:34:17 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template <typename T>
class Array {
	
	private :
	unsigned int _sizearray;
	T *_array;
	
	public :
	Array(void);
	virtual ~Array(void);
	Array(unsigned int n);
	Array(Array const & src);
	Array& operator=(const Array &rhs);
	unsigned int size(void) const;

	
	T& operator[](const unsigned int i);
};

# include "Array.tpp"

#endif