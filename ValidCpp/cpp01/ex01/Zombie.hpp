/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:47:20 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/21 16:01:41 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
using namespace std;

class Zombie{
	private : 
			std::string _name;
	public:
			Zombie();
			Zombie(std::string name);
			~Zombie(void);
			void	setName(std::string name);
			void 	announce();
};

Zombie* newZombie( std::string name );
void	randomChump(std::string name);
Zombie* zombieHorde(int N, std::string name);

#endif