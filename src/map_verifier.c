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
		else if (!(ft_strchr("01CEP\r", buf)))
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
		if (var->map.map[i][ft_strlen(var->map.map[i]) - 1] == '\r')
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
	int	y;
	int	x;

	y = 0;
	while (y < var->map.y)
	{
		x = 0;
		if (y == 0 || (y == var->map.y - 1))
		{
			while (x < var->map.x)
			{
				if (var->map.map[y][x++] != '1')
					put_error(5, var);
			}
		}
		if ((var->map.map[y][0] != '1') || (var->map.map[y][var->map.x - 1] \
			!= '1'))
		{
			put_error(5, var);
		}
		y++;
	}
}

void	path_find(t_game *var, int x, int y)
{
	if (var->map.map[y][x] == '0')
		var->map.map[y][x] = 'O';
	if (var->map.map[y][x] == 'E')
	{
		var->map.map[y][x] = 'e';
		return ;
	}
	if (var->map.map[y][x] == 'C')
		var->map.map[y][x] = 'c';
	if (ft_strchr("0CE", var->map.map[y][x + 1]))
		path_find(var, x + 1, y);
	if (ft_strchr("0CE", var->map.map[y][x - 1]))
		path_find(var, x - 1, y);
	if (ft_strchr("0CE", var->map.map[y + 1][x]))
		path_find(var, x, y + 1);
	if (ft_strchr("0CE", var->map.map[y - 1][x]))
		path_find(var, x, y - 1);
}

void	path_check(t_game *var)
{
	int	x;
	int	y;

	y = 0;
	while (y < var->map.y)
	{
		x = 0;
		while (var->map.map[y][x])
		{
			if ((ft_strchr("CE", var->map.map[y][x])))
				put_error(6, var);
			x++;
		}
		y++;
	}
}
