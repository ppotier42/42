/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:08:35 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/30 16:58:17 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon
{
	private:
		std::string _weapon;
	public:
		Weapon(std::string const &init);
		std::string const & getType(void) const;
		void	setType(std::string type);
		~Weapon(void);
};

#endif