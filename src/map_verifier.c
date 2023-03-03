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

	var->map.c_c = 0;
	var->map.e_c = 0;
	var->map.p_c = 0;
	fd = open(fd_path, O_RDONLY);
	copy_map(var, fd);
	close(fd);
	fd = open(fd_path, O_RDONLY);
	check_map(var, fd);
	close(fd);
}

void	copy_map(t_game *var, int fd)
{
	char	buf;
	int		y;

	if (read(fd, NULL, 0) < 0)
		put_error(1, var);
	y = 1;
	while (read(fd, &buf, 1) > 0)
	{
		if (buf == '\n')
			y++;
		else if (buf == 'C')
			var->map.c_c++;
		else if (buf == 'E')
			var->map.e_c++;
		else if (buf == 'P')
			var->map.p_c++;
		else if (!(ft_strchr("01CEP", buf)))
			put_error(2, var);
	}
	var->map.map_y = y;
	check_counters(var);
}

void	check_counters(t_game *var)
{
	if (var->map.c_c >= 1 && var->map.e_c == 1 && var->map.p_c == 1)
		return ;
	if (var->map.c_c < 1)
		ft_printf("ERROR:\n The map file must have collectibles.");
	if (var->map.e_c < 1)
		ft_printf("ERROR:\n The map file must have an exit.");
	if (var->map.e_c > 1)
		ft_printf("ERROR:\n The map file must only have ONE exit.");
	if (var->map.p_c < 1)
		ft_printf("ERROR:\n The map file must have a starting position");
	if (var->map.p_c > 1)
		ft_printf("ERROR:\n The map file must only have ONE starting position");
	exit(0);
}

void	check_map(t_game *var, int fd)
{
	int	i;

	var->map.map = (char **)malloc(sizeof(char *) * (var->map.map_y + 1));
	if (!var->map.map)
		put_error(3, var);
	i = 0;
	while (i < var->map.map_y)
	{
		var->map.map[i] = get_next_line(fd);
		i++;
	}
	var->map.map[i] = NULL;
	i = 0;
	while (i < var->map.map_y)
	{
		if (var->map.map[i][ft_strlen(var->map.map[i]) - 1] == '\n')
			var->map.map[i][ft_strlen(var->map.map[i]) - 1] = '\0';
		i++;
	}
}
