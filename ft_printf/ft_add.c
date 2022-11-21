/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:40:21 by ppotier           #+#    #+#             */
/*   Updated: 2022/11/21 11:51:34 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar_l(char str)
{
	ft_putchar_fd(str, 1);
	return (1);
}

size_t	ft_add_char(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	ft_putchar_fd(c, 1);
	return (1);
}

size_t	ft_add_str(va_list ap)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	else
	{
		ft_putstr_fd(str, 1);
		i = ft_strlen(str);
	}
	return (i);
}

size_t	ft_putnbr_num(va_list ap)
{
	int		i;
	size_t	len;

	i = va_arg(ap, int);
	len = (size_t)ft_nbrlen(i);
	ft_putnbr_fd(i, 1);
	return (len);
}
