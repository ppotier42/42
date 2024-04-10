/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:54:37 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/30 18:20:55 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <vector>
# include <algorithm>
# include <iostream>

template <typename T>
int	easyfind(T& type, int i)
{
	typename T::const_iterator it = std::find(type.begin(), type.end(), i);
	if (it == type.end()) {
		std::cout << "Value not found" << std::endl;
		return (*it);
	}
	else
		return 	(std::cout << *it << std::endl, *it);
}


#endif