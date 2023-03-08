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
