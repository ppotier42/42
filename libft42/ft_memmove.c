/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <pierre.podnieks@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:06:42 by ppotier           #+#    #+#             */
/*   Updated: 2022/09/15 23:11:51 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	*ft_memmove(void *dst, const void *src, size_t len)
{
	
}
*/
int main()
{
	char src[] = "aled";
	char dst[] = "ca marche comment";
	memmove(dst, src, 17);
	printf("result : %s", dst);
}