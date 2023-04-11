/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:58:25 by ppotier           #+#    #+#             */
/*   Updated: 2023/04/11 11:55:32 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

void	ft_send(int pid, char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
void	ft_putchar(char c);
int		ft_putstr_error(char *s);
int		ft_atoi_mini(char *str);
void	ft_putchar(char c);
void	ft_write(int sig);
char	*ft_strchr(const char *s, int c);

#endif