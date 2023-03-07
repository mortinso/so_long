/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:04:57 by mortins-          #+#    #+#             */
/*   Updated: 2023/03/07 18:23:46 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_pixel_put(t_img *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int	destruct(t_game *var)
{
	mlx_destroy_image(var->mlx, var->sprite.coin);
	mlx_destroy_image(var->mlx, var->sprite.unlock);
	mlx_destroy_image(var->mlx, var->sprite.locked);
	mlx_destroy_image(var->mlx, var->sprite.wall.img);
	mlx_destroy_image(var->mlx, var->sprite.floor.img);
	mlx_destroy_image(var->mlx, var->sprite.player_up);
	mlx_destroy_image(var->mlx, var->sprite.player_left);
	mlx_destroy_image(var->mlx, var->sprite.player_down);
	mlx_destroy_image(var->mlx, var->sprite.player_right);
	mlx_clear_window(var->mlx, var->win);
	mlx_destroy_window(var->mlx, var->win);
	mlx_destroy_display(var->mlx);
	while (var->map.y)
		free(var->map.map[--var->map.y]);
	free(var->map.map);
	free(var->mlx);
	exit (0);
	return (0);
}

int	render_frame(t_game *var)
{
	mlx_put_image_to_window(var->mlx, var->win, var->player.img, var->player.x, \
		var->player.y);
	return (0);
}

int	keypress(int key, t_game *var)
{
	if (key == KEY_ESC)
		destruct(var);
	if (key == KEY_W || key == KEY_UP)
	{
		var->player.img = var->sprite.player_up;
		move(var, 'u');
	}
	if (key == KEY_A || key == KEY_LEFT)
	{
		var->player.img = var->sprite.player_left;
		move(var, 'l');
	}
	if (key == KEY_S || key == KEY_DOWN)
	{
		var->player.img = var->sprite.player_down;
		move(var, 'd');
	}
	if (key == KEY_D || key == KEY_RIGHT)
	{
		var->player.img = var->sprite.player_right;
		move(var, 'r');
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	var;

	if (argc != 2)
		put_error(0, &var);
	get_map(&var, argv[1]);
	var.mlx = mlx_init();
	if (var.mlx == NULL)
		return (put_error(7, &var));
	var.win = mlx_new_window(var.mlx, var.win_width, var.win_height, \
		"Pokemon Rip-Off");
	if (var.win == NULL)
		put_error(8, &var);
	img_init(&var);
	mlx_hook(var.win, 2, 1L << 0, keypress, &var);
	mlx_hook(var.win, 17, 0L, destruct, &var);
	mlx_loop_hook(var.mlx, render_frame, &var);
	mlx_loop(var.mlx);
}
