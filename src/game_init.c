/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:57:15 by mortins-          #+#    #+#             */
/*   Updated: 2023/03/24 13:15:47 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_init(t_game *var)
{
	int	i;
	int	j;

	i = IMG_SIZE;
	j = IMG_SIZE * 3;
	var->sprite.floor.img = mlx_xpm_file_to_image(var->mlx, FLOOR, &i, &i);
	var->sprite.wall.img = mlx_xpm_file_to_image(var->mlx, WALL, &i, &i);
	var->sprite.coin.img = mlx_xpm_file_to_image(var->mlx, COIN, &i, &i);
	var->sprite.lock.img = mlx_xpm_file_to_image(var->mlx, LOCK, &i, &i);
	var->sprite.break_1.img = mlx_xpm_file_to_image(var->mlx, BREAK_1, &i, &i);
	var->sprite.break_2.img = mlx_xpm_file_to_image(var->mlx, BREAK_2, &i, &i);
	var->sprite.break_3.img = mlx_xpm_file_to_image(var->mlx, BREAK_3, &i, &i);
	var->sprite.unlock.img = mlx_xpm_file_to_image(var->mlx, UNLOCK, &i, &i);
	var->sprite.player_up.img = mlx_xpm_file_to_image(var->mlx, PLAYER_U, &i, \
		&i);
	var->sprite.player_left.img = mlx_xpm_file_to_image(var->mlx, PLAYER_L, &i, \
		&i);
	var->sprite.player_down.img = mlx_xpm_file_to_image(var->mlx, PLAYER_D, &i, \
		&i);
	var->sprite.player_right.img = mlx_xpm_file_to_image(var->mlx, PLAYER_R, \
		&i, &i);
	var->sprite.counter.img = mlx_xpm_file_to_image(var->mlx, COUNTER, &j, &i);
	var->map.img.img = mlx_new_image(var->mlx, var->win_width, var->win_height);
	img_init2(var);
}

void	img_init2(t_game *var)
{
	var->player.img.img = mlx_new_image(var->mlx, IMG_SIZE, IMG_SIZE);
	mlx_destroy_image(var->mlx, var->player.img.img);
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
	var->sprite.break_1.addr = mlx_get_data_addr(var->sprite.break_1.img, \
		&var->sprite.break_1.bpp, &var->sprite.break_1.length, \
		&var->sprite.break_1.endian);
	var->sprite.break_2.addr = mlx_get_data_addr(var->sprite.break_2.img, \
		&var->sprite.break_2.bpp, &var->sprite.break_2.length, \
		&var->sprite.break_2.endian);
	var->sprite.break_3.addr = mlx_get_data_addr(var->sprite.break_3.img, \
		&var->sprite.break_3.bpp, &var->sprite.break_3.length, \
		&var->sprite.break_3.endian);
	var->sprite.unlock.addr = mlx_get_data_addr(var->sprite.unlock.img, \
		&var->sprite.unlock.bpp, &var->sprite.unlock.length, \
		&var->sprite.unlock.endian);
	img_addr_2(var);
}

void	img_addr_2(t_game *var)
{
	var->map.img.addr = mlx_get_data_addr(var->map.img.img, \
		&var->map.img.bpp, &var->map.img.length, &var->map.img.endian);
	var->sprite.counter.addr = mlx_get_data_addr(var->sprite.counter.img, \
		&var->sprite.counter.bpp, &var->sprite.counter.length, \
		&var->sprite.counter.endian);
	var->sprite.player_up.addr = mlx_get_data_addr(var->sprite.player_up.img, \
		&var->sprite.player_up.bpp, &var->sprite.player_up.length, \
		&var->sprite.player_up.endian);
	var->sprite.player_left.addr = mlx_get_data_addr(\
		var->sprite.player_left.img, &var->sprite.player_left.bpp, \
		&var->sprite.player_left.length, &var->sprite.player_left.endian);
	var->sprite.player_down.addr = mlx_get_data_addr(\
		var->sprite.player_down.img, &var->sprite.player_down.bpp, \
		&var->sprite.player_down.length, &var->sprite.player_down.endian);
	var->sprite.player_right.addr = mlx_get_data_addr(\
		var->sprite.player_right.img, &var->sprite.player_right.bpp, \
		&var->sprite.player_right.length, &var->sprite.player_right.endian);
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
			if (var->map.map[y][x] == 'c')
				put_tile(var, &var->sprite.coin, x * IMG_SIZE, y * IMG_SIZE);
			else if (var->map.map[y][x] == 'e')
				put_tile(var, &var->sprite.lock, x * IMG_SIZE, y * IMG_SIZE);
			else if (var->map.map[y][x] == 'P')
				put_tile(var, &var->player.img, x * IMG_SIZE, y * IMG_SIZE);
			x++;
		}
		y++;
	}
}
