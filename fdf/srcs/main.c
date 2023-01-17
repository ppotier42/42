/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:28:22 by ppotier           #+#    #+#             */
/*   Updated: 2023/01/17 18:40:16 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlxOS/mlx.h"
#include "../libft/libft.h"
#include "fdf.h"

char	*ft_parseur(char *argv)
{
	t_point	point1;
	int		fd;
	char	**tab;
	char	*ligne;

	fd = open(argv, O_RDONLY);
	ligne = get_next_line(fd);
	if (!ligne)
		free(ligne);
	tab = ft_split(ligne, ' ');
	if (!tab)
		free(tab);
	point1.x = 0;
	point1.y = 0;
	point1.z = ft_atoi(tab[point.y]);
	point1 = point.next;
	printf("%d\n", point.z);
	return (*tab);
}

int	ft_init(char *argv)
{
	t_vars	vars;
	t_img	img;

	(void)argv;
	vars.mlx = mlx_init();
	vars.mlx_window = mlx_new_window(vars.mlx, 600, 600, "FDF");
	img.img = mlx_new_image(vars.mlx, 600, 600);
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
		ft_parseur(argv[1]);
	}
	return (0);
}
