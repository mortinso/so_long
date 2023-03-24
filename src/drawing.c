/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:12:47 by mortins-          #+#    #+#             */
/*   Updated: 2023/03/24 13:12:12 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_frame(t_game *var)
{
	if (var->run == 1)
	{
		if (var->unlocking == 1)
			unlock_animation(var);
		mlx_put_image_to_window(var->mlx, var->win, var->map.img.img, 0, 0);
		var->moves = ft_itoa(var->player.moves);
		mlx_string_put(var->mlx, var->win, (var->win_width - IMG_SIZE + 2), \
			(var->win_height - (IMG_SIZE * 0.4) + 2), 0xFFd0d0c8, \
			var->moves);
		mlx_string_put(var->mlx, var->win, (var->win_width - IMG_SIZE), \
			(var->win_height - (IMG_SIZE * 0.4)), 0xFF606060, \
			var->moves);
		free(var->moves);
	}
	else
		end_animation(var);
	return (0);
}

void	my_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	put_tile(t_game *var, t_img *tile, int screen_x, int screen_y)
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
				my_pixel_put(&var->map.img, screen_x + tile_x, screen_y \
					+ tile_y, *(unsigned int *)color);
			tile_x++;
		}
		tile_y++;
	}
}

void	put_move_counter(t_game *var)
{
	char	*color;
	int		tile_x;
	int		tile_y;

	tile_y = 0;
	while (tile_y < IMG_SIZE)
	{
		tile_x = 0;
		while (tile_x < (IMG_SIZE * 2.5))
		{
			color = var->sprite.counter.addr + (tile_y * \
				var->sprite.counter.length + tile_x * \
				(var->sprite.counter.bpp / 8));
			if (*(unsigned int *)color != GREEN_SCREEN)
				my_pixel_put(&var->map.img, var->win_width - (IMG_SIZE * 2.5) + \
					tile_x, var->win_height - IMG_SIZE + tile_y, \
					*(unsigned int *)color);
			tile_x++;
		}
		tile_y++;
	}
}
