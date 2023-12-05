/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:16:11 by ppotier           #+#    #+#             */
/*   Updated: 2023/12/04 13:59:29 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <iostream>
# include <string>

struct Data {
	Data() : _value(42) {};
	int _value;
	int getValue(){return _value;};
};

class Serializer
{
	private :
	Serializer(void) {return;};
	virtual ~Serializer(void) {return;};
	Serializer(const Serializer& src) {*this = src;};
	Serializer& operator=(const Serializer& rhs) { *this = rhs; return *this;};

	public :
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif