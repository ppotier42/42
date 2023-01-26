/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:28:22 by ppotier           #+#    #+#             */
/*   Updated: 2023/01/24 13:41:04 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_parseur(char *argv, t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = get_height(argv);
	data->width = get_width(argv);
	data->value = (int **)malloc(sizeof(int *) * (data->width + 1));
	i = 0;
	while (i <= data->width)
		data->value[i++] = (int *)malloc(sizeof(int) * (data->height + 1));
	fd = open(argv, O_RDONLY);
	i = 0;
	while (get_next_line_fdf(fd, &line))
	{
		fill_z(data->value[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->value[i] = NULL;
}

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

int	main(int argc, char **argv)
{
	t_data	*data;

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
		data = (t_data *)malloc(sizeof(t_data));
	//todo
		ft_parseur(argv[1], data);
		data->mlx = mlx_init();
		data->mlx_window = mlx_new_window(data->mlx, 1920, 1080, "fdf");
		data->zoom = 60;
		ft_draw_line(data);
		//ft_bresenham(190, 120, 0, 10, data);
		//mlx_key_hook("ECHAP")
		mlx_loop(data->mlx);
	}
	return (0);
}
