/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:25:26 by ppotier           #+#    #+#             */
/*   Updated: 2022/11/14 15:45:27 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	size_t	i;
	va_list	ap;

	i = 0;
	va_start (ap, input);
	while (input[i])
	{
		if (input[i] == '%' && input[i++] == '%')
			write(1, "%", 1);
		else if (input[i] == '%' && input[i++] == 'c')
		{
			ft_putchar_fd(input[i], 1);
		}
		else if (input[i] == '%' && input[i++] == 's')
		{
			ft_putstr_fd((char *)input, 1);
		}
		else if (input[i] == '%' && input[i++] == 'p')
		{
			printf("aled");
		}
		else if (input[i] == '%' && input[i++] == 'd')
		{
			ft_atoi(input);
		}
		else if (input[i] == '%' && input[i++] == 'i')
		{
			printf("aled");
		}
		else if (input[i] == '%' && input[i++] == 'u')
		{
			printf("aled");
		}
		else if (input[i] == '%' && input[i++] == 'x')
		{
			printf("aled");
		}
		else if (input[i] == '%' && input[i++] == 'X')
		{
			printf("aled");
		}
	}
	va_end (ap);
	return (1);
}

int	main()
{
	
}