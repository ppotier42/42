/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:19:40 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/22 11:08:34 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
	private :
		std::string ideas[100];
	public :
		Brain();
		~Brain();

		Brain(Brain const & src);
		Brain & operator=(Brain const & rhs);

		std::string getIdeas(int i) const;
};

#endif