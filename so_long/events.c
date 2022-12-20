/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:53:09 by ppotier           #+#    #+#             */
/*   Updated: 2022/12/20 13:29:10 by ppotier          ###   ########.fr       */
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

	relative_path = "./teapot.xpm";
	img_width = 600;
	img_height = 600;
	mlx = mlx_init();
	img = mlx_new_image(mlx, 1920, 1080);
	img = mlx_xpm_to_image(mlx, &relative_path, &img_width, &img_height);
	mlx_loop(mlx);
}
