/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:38:07 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/21 11:36:50 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iomanip>
#include <iostream>

class FragTrap : public virtual ClapTrap
{
public:
	FragTrap(void);
	FragTrap(std::string name);
	~FragTrap();

	FragTrap & operator=(FragTrap const & rhs);
	FragTrap(FragTrap const &src);
	

	std::string getName(void) const;
	int			getHp(void) const;

	void		highFivesGuys(void);
};

std::ostream & operator<<(std::ostream & o, FragTrap const & rhs);

#endif