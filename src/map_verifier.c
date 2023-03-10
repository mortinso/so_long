/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:02:14 by mortins-          #+#    #+#             */
/*   Updated: 2023/03/08 15:57:14 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_chars(t_game *var, int fd)
{
	char	buf;
	int		y;

	var->map.coin_count = 0;
	var->map.exit_count = 0;
	var->map.player_count = 0;
	if (read(fd, NULL, 0) < 0)
		put_error(1, var);
	y = 1;
	while (read(fd, &buf, 1) > 0)
	{
		if (buf == '\n')
			y++;
		else if (buf == 'C')
			var->map.coin_count++;
		else if (buf == 'E')
			var->map.exit_count++;
		else if (buf == 'P')
			var->map.player_count++;
		else if (!(ft_strchr("01CEP", buf)))
			put_error(2, var);
	}
	var->map.y = y;
	map_counters(var);
}

void	map_size(t_game *var, int fd)
{
	int	i;

	var->map.map = (char **)malloc(sizeof(char *) * (var->map.y + 1));
	if (!var->map.map)
		put_error(3, var);
	i = 0;
	while (i < var->map.y)
		var->map.map[i++] = get_next_line(fd);
	var->map.map[i] = NULL;
	i = 0;
	while (i < var->map.y)
	{
		if (var->map.map[i][ft_strlen(var->map.map[i]) - 1] == '\n')
			var->map.map[i][ft_strlen(var->map.map[i]) - 1] = '\0';
		i++;
	}
	i = 0;
	while (i < (var->map.y - 1))
	{
		if (ft_strlen(var->map.map[i]) != ft_strlen(var->map.map[i + 1]))
			put_error(4, var);
		i++;
	}
	var->map.x = ft_strlen(var->map.map[0]);
}

void	map_walls(t_game *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < var->map.y)
	{
		if (i == 0 || (i == var->map.y - 1))
		{
			while (j < var->map.x)
			{
				if (var->map.map[i][j++] != '1')
					put_error(5, var);
			}
		}
		if ((var->map.map[i][0] != '1') || (var->map.map[i][var->map.x - 1] \
			!= '1'))
		{
			put_error(5, var);
		}
		i++;
		j = 0;
	}
}
