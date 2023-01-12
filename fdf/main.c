/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:28:22 by ppotier           #+#    #+#             */
/*   Updated: 2023/01/12 14:16:09 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxOS/mlx.h"
#include "libft/libft.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
		write(1, "ok", 2);
	if (ft_strchr(argv[1], '.') )
		write(1, "??", 2);
	else
		write(1, "ok", 2);
	return (0);
}
