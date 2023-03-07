#include "so_long.h"

int	keypress(int key, t_game *var)
{
	if (key == KEY_ESC)
		destruct(var);
	if (key == KEY_W || key == KEY_UP)
	{
		var->player.img = var->sprite.player_up;
		move(var, 0, -1);
	}
	if (key == KEY_A || key == KEY_LEFT)
	{
		var->player.img = var->sprite.player_left;
		move(var, -1, 0);
	}
	if (key == KEY_S || key == KEY_DOWN)
	{
		var->player.img = var->sprite.player_down;
		move(var, 0, 1);
	}
	if (key == KEY_D || key == KEY_RIGHT)
	{
		var->player.img = var->sprite.player_right;
		move(var, 1, 0);
	}
	return (0);
}

int	destruct(t_game *var)
{
	mlx_destroy_image(var->mlx, var->sprite.coin);
	mlx_destroy_image(var->mlx, var->sprite.unlock);
	mlx_destroy_image(var->mlx, var->sprite.locked);
	mlx_destroy_image(var->mlx, var->sprite.wall.img);
	mlx_destroy_image(var->mlx, var->sprite.floor.img);
	mlx_destroy_image(var->mlx, var->sprite.player_up);
	mlx_destroy_image(var->mlx, var->sprite.player_left);
	mlx_destroy_image(var->mlx, var->sprite.player_down);
	mlx_destroy_image(var->mlx, var->sprite.player_right);
	mlx_clear_window(var->mlx, var->win);
	mlx_destroy_window(var->mlx, var->win);
	mlx_destroy_display(var->mlx);
	while (var->map.y)
		free(var->map.map[--var->map.y]);
	free(var->map.map);
	free(var->mlx);
	exit (0);
	return (0);
}

void	move(t_game *var, int x, int y)
{
	if ((var->map.map[(var->player.y + (y * IMG_SIZE)) / IMG_SIZE] \
		[(var->player.x + (x * IMG_SIZE)) / IMG_SIZE] != '1'))
	{
		if (!(var->map.map[(var->player.y + (y * IMG_SIZE)) / IMG_SIZE] \
			[(var->player.x + (x * IMG_SIZE)) / IMG_SIZE] == 'E' && \
			var->map.coin_count != 0))
		{
			if ((var->map.map[(var->player.y + (y * IMG_SIZE)) / IMG_SIZE] \
				[(var->player.x + (x * IMG_SIZE)) / IMG_SIZE] == 'C'))
			{
				var->map.coin_count--;
				var->map.map[(var->player.y + (y * IMG_SIZE)) / IMG_SIZE] \
					[(var->player.x + (x * IMG_SIZE)) / IMG_SIZE] = '0';
			}
			var->player.x += x * IMG_SIZE;
			var->player.y += y * IMG_SIZE;
			ft_printf("Number of moves: %d\n", ++var->player.moves);
		}
	}
}
