/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:26:04 by ppotier           #+#    #+#             */
/*   Updated: 2022/11/22 13:57:11 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_base_num(va_list ap)
{
	int			i;
	size_t		len;

	i = va_arg(ap, unsigned int);
	if (i == 0)
	{
		ft_putnbr_fd(0, 1);
		return (1);
	}
	len = (unsigned int)ft_nbrlen_un(i);
	ft_putnbr_un(i, 1);
	return (len);
}
