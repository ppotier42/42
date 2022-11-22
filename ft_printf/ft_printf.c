/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:25:26 by ppotier           #+#    #+#             */
/*   Updated: 2022/11/22 13:24:27 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	dest;
	va_list	ap;

	i = 0;
	dest = 0;
	va_start (ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			dest = dest + ft_format(format, i, ap);
		}
		else
			dest = dest + ft_putchar_l(format[i]);
		i++;
	}
	va_end (ap);
	return (dest);
}

size_t	ft_format(const char *str, size_t start, va_list ap)
{
	size_t	res;

	res = 0;
	if (str[start] == '%')
		res = ft_putchar_l(str[start]);
	else if (str[start] == 'c')
		res = ft_add_char(ap);
	else if (str[start] == 's')
		res = ft_add_str(ap);
	else if (str[start] == 'p')
		return (1);
	else if (str[start] == 'd' || str[start] == 'i')
		res = ft_putnbr_num(ap);
	else if (str[start] == 'u')
		res = ft_base_num(ap);
	else if (str[start] == 'x')
		return (1);
	else if (str[start] == 'X')
		return (1);
	return (res);
}
