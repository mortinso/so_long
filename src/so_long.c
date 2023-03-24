/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:04:57 by mortins-          #+#    #+#             */
/*   Updated: 2023/03/24 14:53:01 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	var;

	if (argc != 2)
		put_error(0, &var);
	get_map(&var, argv[1]);
	var.mlx = mlx_init();
	if (!var.mlx)
		return (put_error(8, &var));
	var.win = mlx_new_window(var.mlx, var.win_width, var.win_height, \
		"Pokemon Rip-Off");
	if (!var.win)
		put_error(9, &var);
	game_init(&var);
	mlx_set_font(var.mlx, var.win, \
		"-schumacher-clean-bold-r-normal--12-120-75-75-c-80-iso646.1991-irv");
	mlx_hook(var.win, 2, 1L << 0, keypress, &var);
	mlx_hook(var.win, 17, 0L, destruct, &var);
	mlx_loop_hook(var.mlx, render_frame, &var);
	mlx_loop(var.mlx);
}
