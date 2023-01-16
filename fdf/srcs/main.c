/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:28:22 by ppotier           #+#    #+#             */
/*   Updated: 2023/01/16 14:30:08 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlxOS/mlx.h"
#include "../libft/libft.h"
#include "fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_init(char *argv)
{
	t_vars	vars;
	t_img	img;

	vars.mlx = mlx_init();
	vars.mlx_window = mlx_new_window(vars.mlx, 600, 600, "FDF");
	printf("%s", "error3");
	img.img = mlx_new_image(vars.mlx, 600, 600);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.mlx_window, img.img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}

int	ft_check_fdf(char *argv)
{
	int	i;

	i = 0;
	i = ft_strlen(argv) - 1;
	if ((argv[i]) != 'f' || (argv[i - 1]) != 'd' || (argv[i - 2]) != 'f'
		|| (argv[i - 3]) != '.')
	{
		perror("Wrong format\n");
		return (0);
	}
	else
		return (1);
}

int	main(int argc, char **argv)
{
	int	init;

	init = 0;
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
	else if (ft_check_fdf(argv[1]) == 1)
	{
		init = ft_init(argv[1]);
	}
	return (init);
}
