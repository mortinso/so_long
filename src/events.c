/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:16:32 by mortins-          #+#    #+#             */
/*   Updated: 2023/03/24 13:12:19 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keypress(int key, t_game *var)
{
	if (key == KEY_ESC)
		destruct(var);
	if ((key == KEY_W || key == KEY_UP) && var->run == 1)
	{
		var->player.img = var->sprite.player_up;
		move(var, 0, -1);
	}
	if ((key == KEY_A || key == KEY_LEFT) && var->run == 1)
	{
		var->player.img = var->sprite.player_left;
		move(var, -1, 0);
	}
	if ((key == KEY_S || key == KEY_DOWN) && var->run == 1)
	{
		var->player.img = var->sprite.player_down;
		move(var, 0, 1);
	}
	if ((key == KEY_D || key == KEY_RIGHT) && var->run == 1)
	{
		var->player.img = var->sprite.player_right;
		move(var, 1, 0);
	}
	return (0);
}

int	destruct(t_game *var)
{
	mlx_destroy_image(var->mlx, var->sprite.coin.img);
	mlx_destroy_image(var->mlx, var->sprite.lock.img);
	mlx_destroy_image(var->mlx, var->sprite.break_1.img);
	mlx_destroy_image(var->mlx, var->sprite.break_2.img);
	mlx_destroy_image(var->mlx, var->sprite.break_3.img);
	mlx_destroy_image(var->mlx, var->sprite.unlock.img);
	mlx_destroy_image(var->mlx, var->sprite.wall.img);
	mlx_destroy_image(var->mlx, var->sprite.floor.img);
	mlx_destroy_image(var->mlx, var->sprite.player_up.img);
	mlx_destroy_image(var->mlx, var->sprite.player_left.img);
	mlx_destroy_image(var->mlx, var->sprite.player_down.img);
	mlx_destroy_image(var->mlx, var->sprite.player_right.img);
	mlx_destroy_image(var->mlx, var->sprite.counter.img);
	mlx_destroy_image(var->mlx, var->map.img.img);
	mlx_clear_window(var->mlx, var->win);
	mlx_destroy_window(var->mlx, var->win);
	if (var->run == 0)
		end_destruct(var);
	mlx_destroy_display(var->mlx);
	while (var->map.y)
		free(var->map.map[--var->map.y]);
	free(var->map.map);
	free(var->mlx);
	exit (0);
	return (0);
}

void	move(t_game *var, int x, int y)
{
	int	pos_x;
	int	pos_y;

	pos_x = var->player.x / IMG_SIZE;
	pos_y = var->player.y / IMG_SIZE;
	put_tile(var, &var->sprite.floor, var->player.x, var->player.y);
	if ((var->map.map[pos_y + y][pos_x + x] != '1'))
	{
		if (var->map.map[pos_y + y][pos_x + x] != 'e' || \
			(var->map.coin_count == 0 && var->unlocking == 0))
		{
			var->player.x += (x * IMG_SIZE);
			var->player.y += (y * IMG_SIZE);
			var->player.moves++;
			if (var->map.map[pos_y + y][pos_x + x] == 'c')
				coins(var);
			if (var->map.map[pos_y + y][pos_x + x] == 'e')
				end_game(var);
		}
	}
	put_tile(var, &var->player.img, var->player.x, var->player.y);
}

void	coins(t_game *var)
{
	put_tile(var, &var->sprite.floor, var->player.x, var->player.y);
	var->map.coin_count--;
	var->map.map[var->player.y / IMG_SIZE][var->player.x / IMG_SIZE] = 'O';
	if (var->map.coin_count == 0)
		var->unlocking = 1;
}
