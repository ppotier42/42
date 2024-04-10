/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:53:35 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/29 14:06:00 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base {
	public :
	virtual ~Base(void) {return ;};
};

class A : public Base{};
class B : public Base{};
class C : public Base{};

#endif