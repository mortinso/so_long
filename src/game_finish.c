/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_finish.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:48:47 by mortins-          #+#    #+#             */
/*   Updated: 2023/03/08 17:53:08 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_animation(t_game *var)
{
	var->end.n++;
	if (var->end.n == 4000)
		var->end.guy = var->end.bike1;
	if (var->end.n == 8000)
		var->end.guy = var->end.bike2;
	if (var->end.n == 12000)
		var->end.guy = var->end.bike3;
	if (var->end.n == 16000)
		var->end.guy = var->end.bike4;
	if (var->end.n == 24000)
		var->end.guy = var->end.bike5;
	if (var->end.n == 28000)
	{
		var->end.n = 0;
		var->end.guy = var->end.bike6;
	}
	mlx_put_image_to_window(var->mlx, var->victor_win, var->end.guy.img, \
			632, 366);
}

void	end_img_init(t_game *var)
{
	int	x;
	int	y;

	x = 320;
	y = 420;
	var->end.bike1.img = mlx_xpm_file_to_image(var->mlx, END_1, &x, &y);
	var->end.bike2.img = mlx_xpm_file_to_image(var->mlx, END_2, &x, &y);
	var->end.bike3.img = mlx_xpm_file_to_image(var->mlx, END_3, &x, &y);
	var->end.bike4.img = mlx_xpm_file_to_image(var->mlx, END_4, &x, &y);
	var->end.bike5.img = mlx_xpm_file_to_image(var->mlx, END_5, &x, &y);
	var->end.bike6.img = mlx_xpm_file_to_image(var->mlx, END_6, &x, &y);
	x = 1280;
	y = 720;
	var->end.screen.img = mlx_xpm_file_to_image(var->mlx, END_SCREEN, &x, &y);
	var->end.guy.img = mlx_new_image(var->mlx, 320, 420);
	mlx_destroy_image(var->mlx, var->end.guy.img);
	var->end.guy = var->end.bike6;
}

void	end_destruct(t_game *var)
{
	mlx_destroy_image(var->mlx, var->end.bike1.img);
	mlx_destroy_image(var->mlx, var->end.bike2.img);
	mlx_destroy_image(var->mlx, var->end.bike3.img);
	mlx_destroy_image(var->mlx, var->end.bike4.img);
	mlx_destroy_image(var->mlx, var->end.bike5.img);
	mlx_destroy_image(var->mlx, var->end.bike6.img);
	mlx_destroy_image(var->mlx, var->end.screen.img);
	mlx_clear_window(var->mlx, var->victor_win);
	mlx_destroy_window(var->mlx, var->victor_win);
}
