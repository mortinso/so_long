/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:04:57 by mortins-          #+#    #+#             */
/*   Updated: 2023/03/01 16:38:46 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define WIN_WIDTH 1408
#define WIN_HEIGHT 896

int	destruct(t_game *var)
{
	mlx_destroy_image(var->mlx, var->player.img);
	mlx_clear_window(var->mlx, var->win);
	mlx_destroy_window(var->mlx, var->win);
	mlx_destroy_display(var->mlx);
	exit (0);
	return (0);
}

int put_error(int n, t_game *var)
{
	if (n == 1)
		ft_printf("Error\nFailed to initiate mlx.");
	if (n == 2)
		ft_printf("Error\nFailed to create a new window.");
	destruct(var);
	return (0);
}

int	render_frame(t_game *var)
{
	mlx_put_image_to_window(var->mlx, var->win, var->player.img, var->player.x, var->player.y);
	return (0);
}

int	keypress(int key, t_game *var)
{
	if (key == KEY_ESC)
		destruct(var);
	if (key == KEY_W || key == KEY_UP)
	{
		if (var->player.y - SPRITE_SIZE >= 0)
			var->player.y -= SPRITE_SIZE;
	}
	if (key == KEY_A || key == KEY_LEFT)
	{
		if (var->player.x - SPRITE_SIZE >= 0)
			var->player.x -= SPRITE_SIZE;
	}
	if (key == KEY_S || key == KEY_DOWN)
	{
		if (var->player.y + (SPRITE_SIZE * 2) <= WIN_HEIGHT)
			var->player.y += SPRITE_SIZE;
	}
	if (key == KEY_D || key == KEY_RIGHT)
	{
		if (var->player.x + (SPRITE_SIZE * 2) <= WIN_WIDTH)
			var->player.x += SPRITE_SIZE;
	}
	return (0);
}

void	imageinit(t_game *var)
{
	int	i = SPRITE_SIZE;

	var->player.img = mlx_xpm_file_to_image(var->mlx, PATH_BALL , &i, &i);
}

int	main(void)
{
	t_game	var;

	var.mlx = mlx_init();
	if (var.mlx == NULL)
		return (put_error(1, &var));
	var.win = mlx_new_window(var.mlx, WIN_WIDTH, WIN_HEIGHT, "so_long");
	if (var.win == NULL)
	{
		free(var.win);
		return (put_error(2, &var));
	}
	var.player.x = 0;
	var.player.y = 0;
	mlx_hook(var.win, 17, 0L, destruct, &var);
	mlx_hook(var.win, 2, 1L<<0, keypress, &var);
	mlx_loop_hook(var.mlx, render_frame, &var);
	mlx_loop(var.mlx);
}
