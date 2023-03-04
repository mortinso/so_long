#include "so_long.h"

void	img_init(t_game *var)
{
	int	i;

	i = SPRITE_SIZE;
	var->sprite.wall = mlx_xpm_file_to_image(var->mlx, PATH_WALL, &i, &i);
	var->sprite.floor = mlx_xpm_file_to_image(var->mlx, PATH_FLOOR, &i, &i);
	var->sprite.player_up = mlx_xpm_file_to_image(var->mlx, \
		PATH_PLAYER_U, &i, &i);
	var->sprite.player_left = mlx_xpm_file_to_image(var->mlx, \
		PATH_PLAYER_L, &i, &i);
	var->sprite.player_down = mlx_xpm_file_to_image(var->mlx, \
		PATH_PLAYER_D, &i, &i);
	var->sprite.player_right = mlx_xpm_file_to_image(var->mlx, \
		PATH_PLAYER_R, &i, &i);
	var->sprite.coin = mlx_xpm_file_to_image(var->mlx, PATH_COIN, &i, &i);
	player_start(var);
}

void	player_start(t_game *var)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	var->player.moves = 0;
	while (y < var->map.y)
	{
		while (x < var->map.x)
		{
			if (var->map.map[y][x] == 'P')
			{
				var->player.x = x * SPRITE_SIZE;
				var->player.y = y * SPRITE_SIZE;
			}
			x++;
		}
		y++;
		x = 0;
	}
	var->player.img = var->sprite.player_down;
}
