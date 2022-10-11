/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:46:53 by ppotier           #+#    #+#             */
/*   Updated: 2022/10/11 11:52:33 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	*ft_memchr(const void *s, int c, size_t n)
{
	
}*/

int main()
{
	char s[] = "comment ca marche";
	int c = 'z';
	printf("result : %s", memchr(s, c, 5));
	return (0);
}