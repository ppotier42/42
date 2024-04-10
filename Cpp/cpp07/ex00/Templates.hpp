/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:49:38 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/29 16:05:37 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP
# include <iostream>
# include <string>

template <typename T>
T const& max(T const & x, T const & y) {return(x>y ? x : y);};

template <typename T>
T const& min(T const & x, T const & y) {return(x<y ? x : y);};

template <typename T>
void swap(T &x, T &y) {
	T tmp;
	tmp = x;
	x = y;
	y = tmp;
};

#endif