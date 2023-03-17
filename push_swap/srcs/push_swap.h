/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:15:21 by ppotier           #+#    #+#             */
/*   Updated: 2023/03/17 14:12:01 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

int		main(int ac, char **av);
void	ft_check_error(int ac, char **argv);
int		ft_isnum(char *num);
int		ft_check_double(int num, char **args, int i);
void	ft_msg_error(char *str);

#endif