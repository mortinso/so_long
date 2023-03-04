/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:02:14 by mortins-          #+#    #+#             */
/*   Updated: 2023/03/03 19:14:47 by mortins-         ###   ########.fr       */
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
	var->win_width = var->map.x * SPRITE_SIZE;
	var->win_height = var->map.y * SPRITE_SIZE;
}

void	map_chars(t_game *var, int fd)
{
	char	buf;
	int		y;

	var->map.c_count = 0;
	var->map.e_count = 0;
	var->map.p_count = 0;
	if (read(fd, NULL, 0) < 0)
		put_error(1, var);
	y = 1;
	while (read(fd, &buf, 1) > 0)
	{
		if (buf == '\n')
			y++;
		else if (buf == 'C')
			var->map.c_count++;
		else if (buf == 'E')
			var->map.e_count++;
		else if (buf == 'P')
			var->map.p_count++;
		else if (!(ft_strchr("01CEP\r", buf))) /* REMOVE '\r'WHEN WORKING ON LINUX */
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
		if (var->map.map[i][ft_strlen(var->map.map[i]) - 1] == '\r') /* REMOVE WHEN WORKING ON LINUX */
			var->map.map[i][ft_strlen(var->map.map[i]) - 1] = '\0'; /* REMOVE WHEN WORKING ON LINUX */
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
