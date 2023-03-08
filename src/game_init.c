/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:57:15 by mortins-          #+#    #+#             */
/*   Updated: 2023/03/08 17:29:15 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_init(t_game *var)
{
	int	i;

	i = IMG_SIZE;
	var->sprite.unlock.img = mlx_xpm_file_to_image(var->mlx, PATH_UNLOCK, &i, \
		&i);
	var->sprite.lock.img = mlx_xpm_file_to_image(var->mlx, PATH_LOCK, &i, &i);
	var->sprite.coin.img = mlx_xpm_file_to_image(var->mlx, PATH_COIN, &i, &i);
	var->sprite.player_up.img = mlx_xpm_file_to_image(var->mlx, \
		PATH_PLAYER_U, &i, &i);
	var->sprite.player_left.img = mlx_xpm_file_to_image(var->mlx, \
		PATH_PLAYER_L, &i, &i);
	var->sprite.player_down.img = mlx_xpm_file_to_image(var->mlx, \
		PATH_PLAYER_D, &i, &i);
	var->sprite.player_right.img = mlx_xpm_file_to_image(var->mlx, \
		PATH_PLAYER_R, &i, &i);
	var->sprite.wall.img = mlx_xpm_file_to_image(var->mlx, PATH_WALL, &i, &i);
	var->sprite.floor.img = mlx_xpm_file_to_image(var->mlx, PATH_FLOOR, &i, &i);
	var->map.img.img = mlx_new_image(var->mlx, var->win_width, var->win_height);
	var->player.img.img = mlx_new_image(var->mlx, IMG_SIZE, IMG_SIZE);

}

void	img_addr(t_game *var)
{
	var->sprite.wall.addr = mlx_get_data_addr(var->sprite.wall.img, \
		&var->sprite.wall.bpp, &var->sprite.wall.length, \
		&var->sprite.wall.endian);
	var->sprite.floor.addr = mlx_get_data_addr(var->sprite.floor.img, \
		&var->sprite.floor.bpp, &var->sprite.floor.length, \
		&var->sprite.floor.endian);
	var->sprite.coin.addr = mlx_get_data_addr(var->sprite.coin.img, \
		&var->sprite.coin.bpp, &var->sprite.coin.length, \
		&var->sprite.coin.endian);
	var->sprite.lock.addr = mlx_get_data_addr(var->sprite.lock.img, \
		&var->sprite.lock.bpp, &var->sprite.lock.length, \
		&var->sprite.lock.endian);
	var->sprite.unlock.addr = mlx_get_data_addr(var->sprite.unlock.img, \
		&var->sprite.unlock.bpp, &var->sprite.unlock.length, \
		&var->sprite.unlock.endian);
	var->map.img.addr = mlx_get_data_addr(var->map.img.img, \
		&var->map.img.bpp, &var->map.img.length, &var->map.img.endian);
	img_addr_2(var);
}

void	img_addr_2(t_game *var)
{
	var->sprite.player_up.addr = mlx_get_data_addr(var->sprite.player_up.img, \
		&var->sprite.player_up.bpp, &var->sprite.player_up.length, \
		&var->sprite.player_up.endian);
	var->sprite.player_left.addr = mlx_get_data_addr(\
		var->sprite.player_left.img, &var->sprite.player_left.bpp, \
		&var->sprite.player_left.length, &var->sprite.player_left.endian);
	var->sprite.player_down.addr = mlx_get_data_addr(var->sprite.player_down.img, \
		&var->sprite.player_down.bpp, &var->sprite.player_down.length, \
		&var->sprite.player_down.endian);
	var->sprite.player_right.addr = mlx_get_data_addr(\
		var->sprite.player_right.img, &var->sprite.player_right.bpp, \
		&var->sprite.player_right.length, &var->sprite.player_right.endian);
	var->player.img.addr = mlx_get_data_addr(var->player.img.img, \
		&var->player.img.bpp, &var->player.img.length, \
		&var->player.img.endian);
	var->player.img.addr = mlx_get_data_addr(var->player.img.img, \
		&var->player.img.bpp, &var->player.img.length, &var->player.img.endian);
	var->player.img = var->sprite.player_down;
}

void	make_map(t_game *var)
{
	int	x;
	int	y;

	y = 0;
	while (y < var->map.y)
	{
		x = 0;
		while (x < var->map.x)
		{
			put_tile(var, &var->sprite.floor, x * IMG_SIZE, y * IMG_SIZE);
			if (var->map.map[y][x] == '1' )
				put_tile(var, &var->sprite.wall, x * IMG_SIZE, y * IMG_SIZE);
			if (ft_strchr("CEP", var->map.map[y][x]))
				make_extras(var, x, y);
			x++;
		}
		y++;
	}
}

void	make_extras(t_game *var, int x, int y)
{
	if (var->map.map[y][x] == 'C')
		put_tile(var, &var->sprite.coin, x * IMG_SIZE, y * IMG_SIZE);
	else if (var->map.map[y][x] == 'E')
	{
		put_tile(var, &var->sprite.lock, x * IMG_SIZE, y * IMG_SIZE);
		var->map.exit_x = x * IMG_SIZE;
		var->map.exit_y = y * IMG_SIZE;
	}
	else if (var->map.map[y][x] == 'P')
	{
		put_tile(var, &var->player.img, x * IMG_SIZE, y * IMG_SIZE);
		var->player.x = x * IMG_SIZE;
		var->player.y = y * IMG_SIZE;
	}
}
