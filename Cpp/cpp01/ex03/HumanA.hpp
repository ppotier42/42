/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:13:07 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/30 16:38:23 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{
private:
	std::string _name;
	Weapon		&_weapon;
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack(void) const;
};

#endif