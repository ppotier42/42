/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:28:22 by ppotier           #+#    #+#             */
/*   Updated: 2023/01/09 14:51:34 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxOS/mlx.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_printf("Not enough arguments");
	else if (argc == 2)
		ft_untruc(argv[1]);
	else if (argc < 2)
		ft_printf("too many arguments");
	return (0);
}
