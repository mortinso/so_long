/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verifier2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:13:39 by mortins-          #+#    #+#             */
/*   Updated: 2023/03/22 16:13:40 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_positions(t_game *var)
{
	int	x;
	int	y;

	y = 0;
	while (y < var->map.y)
	{
		x = 0;
		while (var->map.map[y][x])
		{
			if (var->map.map[y][x] == 'E')
			{
				var->map.exit_x = x * IMG_SIZE;
				var->map.exit_y = y * IMG_SIZE;
			}
			else if (var->map.map[y][x] == 'P')
			{
				var->player.x = x * IMG_SIZE;
				var->player.y = y * IMG_SIZE;
			}
			x++;
		}
		y++;
	}
}
