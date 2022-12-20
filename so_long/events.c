/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:53:09 by ppotier           #+#    #+#             */
/*   Updated: 2022/12/20 15:57:45 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxOS/mlx.h"

int	main(void)
{
	void	*mlx;
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
	void	*mlx_win;

	relative_path = "./item.xpm";
	mlx = mlx_init();
	img = mlx_new_image(mlx, 1920, 1080);
	(void)mlx_win;
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, 600, 600, 0);
	mlx_loop(mlx);
}
