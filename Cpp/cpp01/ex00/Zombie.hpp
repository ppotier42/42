/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:20:05 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/18 18:06:15 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
// # include <iomanip>
# include <string>
using namespace std;

class Zombie{
	private : 
			std::string _name;
	public:
			Zombie(std::string name);
			~Zombie(void);
		void 	announce() const;
};

Zombie* newZombie( std::string name );
void	randomChump(std::string name);

#endif