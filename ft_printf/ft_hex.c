/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:26:04 by ppotier           #+#    #+#             */
/*   Updated: 2022/11/22 15:22:37 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_base_len(size_t nbr, char *base)
{
	size_t	count;
	size_t	len;

	count = 0;
	len = ft_strlen(base);
	while (nbr != 0)
	{
		nbr /= len;
		count++;
	}
	return (count);
}

void	ft_put_base(size_t nbr, char *base)
{
	size_t	len;

	len = ft_strlen(base);
	if (nbr >= len)
	{
		ft_print_hex(nbr / len, base);
		ft_print_hex(nbr % len, base);
	}
	else
		ft_putchar_fd(base[nbr], 1);
}

size_t	ft_print_hex(size_t nbr, char *base)
{
	size_t	len;

	if (nbr == 0)
	{
		ft_putnbr_fd(0, 1);
		return (1);
	}
	ft_put_base(nbr, base);
	len = ft_base_len(nbr, base);
	return (len);
}

size_t	ft_hex(va_list ap, char c)
{
	size_t	nbr;
	size_t	count;

	nbr = va_arg(ap, unsigned int);
	count = 0;
	if (c == 'x')
		count = ft_print_hex(nbr, "0123456789abcdef");
	else if (c == 'X')
		count = ft_print_hex(nbr, "0123456789ABCDEF");
	return (count);
}
