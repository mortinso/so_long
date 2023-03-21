/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_hubs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:56:44 by mortins-          #+#    #+#             */
/*   Updated: 2023/03/08 17:51:55 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map(t_game *var, char *fd_path)
{
	int	fd;

	fd = open(fd_path, O_RDONLY);
	map_chars(var, fd);
	close(fd);
	fd = open(fd_path, O_RDONLY);
	map_size(var, fd);
	close(fd);
	map_walls(var);
	var->win_width = var->map.x * IMG_SIZE;
	var->win_height = var->map.y * IMG_SIZE;
}

void	game_init(t_game *var)
{
	var->player.moves = 0;
	img_init(var);
	img_addr(var);
	make_map(var);
	var->run = 1;
}

void	end_game(t_game *var)
{
	var->run = 0;
	var->victor_win = mlx_new_window(var->mlx, 1280, 720, \
		"CONGRATS!!!");
	if (var->victor_win == NULL)
		put_error(8, var);
	var->end.n = 0;
	end_img_init(var);
	mlx_put_image_to_window(var->mlx, var->victor_win, var->end.screen.img, \
		0, 0);
	mlx_hook(var->victor_win, 2, 1L << 0, keypress, var);
	mlx_hook(var->victor_win, 17, 0L, destruct, var);
}
