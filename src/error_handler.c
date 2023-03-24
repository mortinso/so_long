/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:57:23 by mortins-          #+#    #+#             */
/*   Updated: 2023/03/24 14:55:30 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_error(int error, t_game *var)
{
	if (error == 0)
		ft_printf("ERROR:\n Input ONE map file.");
	if (error == 1)
		ft_printf("ERROR:\n The map file is empty.");
	if (error == 2)
		ft_printf("ERROR:\n The map file contains a forbidden character.");
	if (error == 3)
		ft_printf("ERROR:\n Failed to allocate memory.");
	if (error >= 4 && error <= 7)
	{
		if (error == 4)
			ft_printf("ERROR:\n Empty line at EOF.");
		if (error == 5)
			ft_printf("ERROR:\n The map must be rectangular.");
		if (error == 6)
			ft_printf("ERROR:\n The map must be surrounded by walls.");
		if (error == 7)
			ft_printf("ERROR:\n The map must have a valid path.");
		while (var->map.y)
			free(var->map.map[--var->map.y]);
		free(var->map.map);
	}
	put_error2(error, var);
	return (0);
}

int	put_error2(int error, t_game *var)
{
	if (error == 8)
		ft_printf("ERROR\n Failed to initiate mlx.");
	if (error == 9)
	{
		ft_printf("ERROR\n Failed to create a new window.");
		free(var->mlx);
	}
	if (error == 10)
		ft_printf("ERROR\n Map file must end with the '.ber' extension.");
	exit(0);
}

void	map_counters(t_game *var)
{
	if (var->map.coin_count >= 1 && var->map.exit_count == 1 && \
		var->map.player_count == 1)
		return ;
	if (var->map.coin_count < 1)
		ft_printf("ERROR:\n The map file must have collectibles.");
	if (var->map.exit_count < 1)
		ft_printf("ERROR:\n The map file must have an exit.");
	if (var->map.exit_count > 1)
		ft_printf("ERROR:\n The map file must only have ONE exit.");
	if (var->map.player_count < 1)
		ft_printf("ERROR:\n The map file must have a starting position");
	if (var->map.player_count > 1)
		ft_printf("ERROR:\n The map file must only have ONE starting position");
	exit(0);
}
