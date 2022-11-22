/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:46:36 by ppotier           #+#    #+#             */
/*   Updated: 2022/11/22 12:55:02 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include "./libft/libft.h"
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *input, ...);
size_t	ft_putnbr_num(va_list ap);
size_t	ft_add_str(va_list ap);
size_t	ft_add_char(va_list ap);
size_t	ft_putchar_l(char str);
int		ft_nbrlen(int n);
size_t	ft_format(const char *str, size_t start, va_list ap);

#endif
