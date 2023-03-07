/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:57:15 by mortins-          #+#    #+#             */
/*   Updated: 2023/03/07 18:59:42 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *var)
{
	var->player.moves = 0;
	img_init(var);
	var->map.img.img = mlx_new_image(var->mlx, var->win_width, var->win_height);
	var->map.img.addr = mlx_get_data_addr(var->map.img.img, \
		&var->map.img.bpp, &var->map.img.length, &var->map.img.endian);
	make_map(var);
}

void	img_init(t_game *var)
{
	int	i;

	i = IMG_SIZE;
	var->sprite.unlock = mlx_xpm_file_to_image(var->mlx, PATH_UNLOCK, &i, &i);
	var->sprite.locked = mlx_xpm_file_to_image(var->mlx, PATH_LOCKED, &i, &i);
	var->sprite.coin = mlx_xpm_file_to_image(var->mlx, PATH_COIN, &i, &i);
	var->sprite.player_up = mlx_xpm_file_to_image(var->mlx, \
		PATH_PLAYER_U, &i, &i);
	var->sprite.player_left = mlx_xpm_file_to_image(var->mlx, \
		PATH_PLAYER_L, &i, &i);
	var->sprite.player_down = mlx_xpm_file_to_image(var->mlx, \
		PATH_PLAYER_D, &i, &i);
	var->sprite.player_right = mlx_xpm_file_to_image(var->mlx, \
		PATH_PLAYER_R, &i, &i);
	var->sprite.wall.img = mlx_xpm_file_to_image(var->mlx, PATH_WALL, &i, &i);
	var->sprite.wall.addr = mlx_get_data_addr(var->sprite.wall.img, \
		&var->sprite.wall.bpp, &var->sprite.wall.length, \
		&var->sprite.wall.endian);
	var->sprite.floor.img = mlx_xpm_file_to_image(var->mlx, PATH_FLOOR, &i, &i);
	var->sprite.floor.addr = mlx_get_data_addr(var->sprite.floor.img, \
		&var->sprite.floor.bpp, &var->sprite.floor.length, \
		&var->sprite.floor.endian);
	var->player.img = var->sprite.player_down;
	var->sprite.exit = var->sprite.locked;
}

void	make_map(t_game *var)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < var->map.y)
	{
		while (x < var->map.x)
		{
			if (ft_strchr("0CEP", var->map.map[y][x]))
			{
				put_tile(var, &var->sprite.floor, x * IMG_SIZE, y * IMG_SIZE);
				if (var->map.map[y][x] == 'P')
				{
					var->player.x = x * IMG_SIZE;
					var->player.y = y * IMG_SIZE;
				}
			}
			else if (var->map.map[y][x] == '1' )
				put_tile(var, &var->sprite.wall, x * IMG_SIZE, y * IMG_SIZE);
			x++;
		}
		y++;
		x = 0;
	}
}

void	put_tile(t_game *var, t_img *tile, int map_x, int map_y)
{
	char	*color;
	int		tile_x;
	int		tile_y;

	tile_x = 0;
	tile_y = 0;
	while (tile_y < IMG_SIZE)
	{
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
		tile_x = 0;
		tile_y++;
	}
}
