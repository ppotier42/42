/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:19:11 by ppotier           #+#    #+#             */
/*   Updated: 2023/12/21 15:21:46 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <iostream>
#include <stdexcept>

static std::vector<std::vector<unsigned int> > fds(const std::vector<std::vector<unsigned int> > &left, const std::vector<std::vector<unsigned int> > &right)
{
	std::vector<std::vector<unsigned int> > res;
	unsigned int i = 0, j = 0;
	while (i < left.size() && j < right.size()) {
		if (left[i][0] < right[j][0]) {
			res.push_back(left[i]);
			i++;
		} else {
			res.push_back(right[j]);
			j++;
		}
	}
	for (; i < left.size(); i++)
		res.push_back(left[i]);
	for (; j < right.size(); j++)
		res.push_back(right[j]);
	return (res);
}



static std::vector<std::vector<unsigned int> > ft_Sort(std::vector<std::vector<unsigned int> > &group)
{
	if (group.empty())
		throw std::runtime_error("Vector is empty");
	if (group.size() == 1)
		return group;
	std::vector<std::vector<unsigned int > > left(group.begin(), group.begin() + group.size() / 2);
	std::vector<std::vector<unsigned int > > right(group.begin() + group.size() / 2, group.end());
	left = ft_Sort(left);
	right = ft_Sort(right);
	return (fds(left, right));
}

static void	insertSort(std::vector<unsigned int> &vec) 
{
	unsigned int tmp;
	for (unsigned int i = 1; i < vec.size(); i++)
	{
		unsigned int j = i;
		while (j > 0 && vec[j - 1] > vec[j]) {
			tmp = vec[j - 1];
			vec[j - 1] = vec[j];
			vec[j] = tmp;
			j--;
		}
	}
}

static void	printSorted(std::vector<unsigned int> vec)
{
	std::cout << "After:\t";
	for (std::vector<unsigned int>::iterator i = vec.begin(); i != vec.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
}

PmergeMe::PmergeMe(std::vector<unsigned int> &vec)
{
	std::vector<unsigned int> res = vec;

	for (unsigned int grpsize = 5; grpsize > 0; grpsize /= 2) {
		std::vector<std::vector<unsigned int> > group;
		for (unsigned int i = 0; i < res.size(); i += grpsize) {
			std::vector<unsigned int> tmp;
			for (unsigned int j = 0; j < grpsize && i + j < res.size(); j++)
				tmp.push_back(res[i + j]);
			group.push_back(tmp);
		}
		res.clear();
		// Insert and sort
		for (unsigned int i = 0; i < group.size(); i++)
			insertSort(group[i]);
		
		group = ft_Sort(group);
		for (unsigned int i = 0; i < group.size(); i++)
			for(unsigned int j = 0; j < group[i].size(); j++)
				res.push_back(group[i][j]);
		}
	printSorted(res);
	return ;
}

static std::deque<std::deque<unsigned int> > fdsDeq(const std::deque<std::deque<unsigned int> > &left, const std::deque<std::deque<unsigned int> > &right)
{
	std::deque<std::deque<unsigned int> > res;
	unsigned int i = 0, j = 0;
	while (i < left.size() && j < right.size()) {
		if (left[i][0] < right[j][0]) {
			res.push_back(left[i]);
			i++;
		} else {
			res.push_back(right[j]);
			j++;
		}
	}
	for (; i < left.size(); i++)
		res.push_back(left[i]);
	for (; j < right.size(); j++)
		res.push_back(right[j]);
	return (res);
}

static std::deque<std::deque<unsigned int> > ft_SortDeq(std::deque<std::deque<unsigned int> > &group)
{
	if (group.empty())
		throw std::runtime_error("Deque is empty");
	if (group.size() == 1)
		return group;
	std::deque<std::deque<unsigned int > > left(group.begin(), group.begin() + group.size() / 2);
	std::deque<std::deque<unsigned int > > right(group.begin() + group.size() / 2, group.end());
	left = ft_SortDeq(left);
	right = ft_SortDeq(right);
	return (fdsDeq(left, right));
}

static void	insertSortDeq(std::deque<unsigned int> &deq) 
{
	unsigned int tmp;
	for (unsigned int i = 1; i < deq.size(); i++)
	{
		unsigned int j = i;
		while (j > 0 && deq[j - 1] > deq[j]) {
			tmp = deq[j - 1];
			deq[j - 1] = deq[j];
			deq[j] = tmp;
			j--;
		}
	}
}

static void	printSortedDeq(std::deque<unsigned int> deq)
{
	std::cout << "After:\t";
	for (std::deque<unsigned int>::iterator i = deq.begin(); i != deq.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
}

PmergeMe::PmergeMe(std::deque<unsigned int> &deq)
{
	std::deque<unsigned int> res = deq;

	for (unsigned int grpsize = 5; grpsize > 0; grpsize /= 2) {
		std::deque<std::deque<unsigned int> > group;
		for (unsigned int i = 0; i < res.size(); i += grpsize) {
			std::deque<unsigned int> tmp;
			for (unsigned int j = 0; j < grpsize && i + j < res.size(); j++)
				tmp.push_back(res[i + j]);
			group.push_back(tmp);
		}
		res.clear();
		// Insert and sort
		for (unsigned int i = 0; i < group.size(); i++)
			insertSortDeq(group[i]);
		
		group = ft_SortDeq(group);
		for (unsigned int i = 0; i < group.size(); i++)
			for(unsigned int j = 0; j < group[i].size(); j++)
				res.push_back(group[i][j]);
		}
	printSortedDeq(res);
	return ;
}
