/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:57:23 by mortins-          #+#    #+#             */
/*   Updated: 2023/03/07 14:57:34 by mortins-         ###   ########.fr       */
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
	if (error == 4)
		ft_printf("ERROR:\n The map must be rectangular.");
	if (error == 5)
		ft_printf("ERROR:\n The map must be surrounded by walls.");
	if (error == 6)
		ft_printf("ERROR:\n The map must have a valid path.");
	if (error == 7)
		ft_printf("ERROR\n Failed to initiate mlx.");
	if (error == 8)
	{
		ft_printf("ERROR\n Failed to create a new window.");
		free(var->mlx);
	}
	exit(0);
	return (0);
}

void	map_counters(t_game *var)
{
	if (var->map.c_count >= 1 && var->map.e_count == 1 && var->map.p_count == 1)
		return ;
	if (var->map.c_count < 1)
		ft_printf("ERROR:\n The map file must have collectibles.");
	if (var->map.e_count < 1)
		ft_printf("ERROR:\n The map file must have an exit.");
	if (var->map.e_count > 1)
		ft_printf("ERROR:\n The map file must only have ONE exit.");
	if (var->map.p_count < 1)
		ft_printf("ERROR:\n The map file must have a starting position");
	if (var->map.p_count > 1)
		ft_printf("ERROR:\n The map file must only have ONE starting position");
	exit(0);
}
