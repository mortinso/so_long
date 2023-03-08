/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:12:47 by mortins-          #+#    #+#             */
/*   Updated: 2023/03/08 18:33:27 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* "-schumacher-clean-bold-r-normal--16-160-*-*-*-*-*-*" */
int	render_frame(t_game *var)
{
	if (var->run == 1)
		mlx_put_image_to_window(var->mlx, var->win, var->map.img.img, 0, 0);
	/* mlx_ */
	return (0);
}
void	put_tile(t_game *var, t_img *tile, int map_x, int map_y)
{
	char	*color;
	int		tile_x;
	int		tile_y;

	tile_y = 0;
	while (tile_y < IMG_SIZE)
	{
		tile_x = 0;
		while (tile_x < IMG_SIZE)
		{
			color = tile->addr + (tile_y * tile->length + tile_x * \
				(tile->bpp / 8));
			if (*(unsigned int *)color != GREEN_SCREEN)
			{
				my_pixel_put(&var->map.img, map_x + tile_x, map_y \
					+ tile_y, *(unsigned int *)color);
			}
			tile_x++;
		}
		tile_y++;
	}
}

void	my_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}
