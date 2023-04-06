/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:15:21 by ppotier           #+#    #+#             */
/*   Updated: 2023/04/06 14:14:45 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_data
{
	int	*a;
	int	*b;

}	t_data;

int		main(int ac, char **av);
void	ft_check_error(int ac, char **argv);
int		ft_isnum(char *num);
int		ft_check_double(int num, char **args, int i);
void	ft_msg_error(char *str);
void	ft_free(char **str);
void	ft_push_swap(int ac, char **av);
void	ft_quick_sort(t_data *data, unsigned int i);
int		ft_is_sorted(int *a);

#endif