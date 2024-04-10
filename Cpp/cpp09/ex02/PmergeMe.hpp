/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:16:44 by ppotier           #+#    #+#             */
/*   Updated: 2023/12/21 10:36:12 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <vector>
# include <deque>

class PmergeMe {
	private :
	PmergeMe() {};

	public :
	PmergeMe(std::vector<unsigned int> &vec);
   	PmergeMe(std::deque<unsigned int> &deq);
	~PmergeMe() {};
	// PmergeMe(const PmergeMe &src);
	// PmergeMe &operator=(const PmergeMe &src);
};


#endif