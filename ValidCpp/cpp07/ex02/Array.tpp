/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:08:35 by ppotier           #+#    #+#             */
/*   Updated: 2023/12/05 11:32:01 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array(void) : _array(NULL), _sizearray(0) {};

template <typename T>
Array<T>::Array(unsigned int n) : _sizearray(n), _array(new T[n]) {}

template <typename T>
Array<T>::~Array(void)
{
	if (_array != NULL)
		delete _array;
	return ;
}

template <typename T>
Array<T>::Array(const Array & src) : _sizearray(src._sizearray)
{
	_array = new T[src._sizearray];
	for (int i = 0; i < src._sizearray; i++)
		_array[i] = src._array[i];
}

template <typename T>
Array<T> & Array<T>::operator=(const Array &rhs)
{
	if (rhs != NULL && rhs._sizearray > 0)
	{
		delete _array;
		_array = new T[rhs._sizearray];
		_sizearray = rhs._sizearray;
		for (int i = 0; i < _sizearray; i++)
			_array[i] = rhs._array[i];
	}
	return (*this);
}

template <typename T>
T & Array<T>::operator[](const unsigned int i)
{
	if (i > _sizearray)
		throw std::out_of_range("Index is too big");
	return (_array[i]);
}

template <typename T>
unsigned int Array<T>::size(void) const {return (_sizearray);};


#endif