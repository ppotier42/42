/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:28:22 by ppotier           #+#    #+#             */
/*   Updated: 2023/01/31 23:19:07 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_check_fdf(char *argv)
{
	int	i;

	i = 0;
	i = ft_strlen(argv) - 1;
	if (i <= 4 || (argv[i]) != 'f' || (argv[i - 1]) != 'd'
		|| (argv[i - 2]) != 'f' || (argv[i - 3]) != '.')
	{
		perror("Wrong format\n");
		return (0);
	}
	else
		return (1);
}

int	ft_error(int argc)
{	
	if (argc > 2)
	{
		errno = 7;
		perror("Too many arguments\n");
	}
	else if (argc < 2)
	{
		errno = 22;
		perror("Not enough argument\nFormat is ./.fdf maps/42.fdf \n");
	}
	return (argc);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_vars	vars;
	printf("main\n");
	ft_error(argc);
	if (ft_check_fdf(argv[1]) == 1)
	{
		ft_parseur(argv[1], &data);
		data.shift_x = 1920 / 2;
		data.shift_y = 1080 / 2;
		data.angle_x = 45;
		data.angle_y = 45;
		data.angle_z = 0;
		data.zoom = 20;
		data.lift = 1;
		vars.mlx = mlx_init();
		vars.mlx_win = mlx_new_window(vars.mlx, 1920, 1080, "FDF");
		vars.img = mlx_new_image(vars.mlx, 1920, 1080);
		vars.addr = mlx_get_data_addr(vars.img, &vars.bpp, \
										&vars.line_length, &vars.endian);
		draw(&data, vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
