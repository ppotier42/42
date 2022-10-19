/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:00:17 by ppotier           #+#    #+#             */
/*   Updated: 2022/10/19 15:43:43 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = n * (-1);
		}
		if (n > 10)
		{
			ft_putnbr_fd(n / 10, fd);
			n = n % 10;
		}
		if (n >= 0 && n < 10)
			ft_putchar_fd((n + '0'), fd);
	}
}

/*int main()
{
	int n = 1298;
	ft_putnbr_fd(n, 2);
}*/