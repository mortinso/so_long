/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:02:20 by mortins-          #+#    #+#             */
/*   Updated: 2023/03/08 17:51:28 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../utils/ft_printf/ft_printf.h"
# include "../utils/get_next_line/get_next_line.h"
# include "../utils/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define IMG_SIZE 64

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

# define GREEN_SCREEN 0x00dc00ff

# define PATH_PLAYER_U "sprites/player_u.xpm"
# define PATH_PLAYER_L "sprites/player_l.xpm"
# define PATH_PLAYER_D "sprites/player_d.xpm"
# define PATH_PLAYER_R "sprites/player_r.xpm"
# define PATH_COIN "sprites/coin.xpm"
# define PATH_WALL "sprites/wall.xpm"
# define PATH_FLOOR "sprites/floor.xpm"
# define PATH_UNLOCK "sprites/unlocked.xpm"
# define PATH_LOCK "sprites/locked.xpm"

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		endian;
}	t_img;

typedef struct s_player {
	t_img	img;
	int		x;
	int		y;
	int		moves;
}	t_player;

typedef struct s_sprite {
	t_img	player_up;
	t_img	player_left;
	t_img	player_down;
	t_img	player_right;
	t_img	coin;
	t_img	wall;
	t_img	floor;
	t_img	lock;
	t_img	unlock;
}	t_sprite;

typedef struct s_map {
	char	**map;
	t_img	img;
	int		y;
	int		x;
	int		coin_count;
	int		exit_count;
	int		player_count;
	int		exit_x;
	int		exit_y;
}	t_map;

typedef struct s_game {
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	int			run;
	t_map		map;
	t_sprite	sprite;
	t_player	player;
}	t_game;

void	get_map(t_game *var, char *fd_path);
void	map_chars(t_game *var, int fd);
void	map_counters(t_game *var);
void	map_size(t_game *var, int fd);
void	map_walls(t_game *var);
int		put_error(int error, t_game *var);
void	game_init(t_game *var);
void	img_init(t_game *var);
void	img_addr(t_game *var);
void	img_addr_2(t_game *var);
void	make_map(t_game *var);
void	make_extras(t_game *var, int x, int y);
void	put_tile(t_game *var, t_img *tile, int map_x, int map_y);
void	my_pixel_put(t_img *data, int x, int y, int color);
int		keypress(int key, t_game *var);
void	move(t_game *var, int x, int y);
void	coins(t_game *var);
int		destruct(t_game *var);
int		render_frame(t_game *var);
void	end_game(t_game *var);

#endif
