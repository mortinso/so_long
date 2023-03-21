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

# define IMG_SIZE 48

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

# define PATH_PLAYER_U "sprites/48/player_u.xpm"
# define PATH_PLAYER_L "sprites/48/player_l.xpm"
# define PATH_PLAYER_D "sprites/48/player_d.xpm"
# define PATH_PLAYER_R "sprites/48/player_r.xpm"
# define PATH_COIN "sprites/48/coin.xpm"
# define PATH_WALL "sprites/48/wall.xpm"
# define PATH_FLOOR "sprites/48/floor.xpm"
# define PATH_UNLOCK "sprites/48/unlocked.xpm"
# define PATH_LOCK "sprites/48/locked.xpm"

# define END_1 "sprites/end/bike1.xpm"
# define END_2 "sprites/end/bike2.xpm"
# define END_3 "sprites/end/bike3.xpm"
# define END_4 "sprites/end/bike4.xpm"
# define END_5 "sprites/end/bike5.xpm"
# define END_6 "sprites/end/bike6.xpm"
# define END_SCREEN "sprites/end/screen.xpm"

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

typedef struct s_endgame {
	long	n;
	t_img	bike1;
	t_img	bike2;
	t_img	bike3;
	t_img	bike4;
	t_img	bike5;
	t_img	bike6;
	t_img	guy;
	t_img	screen;
}	t_endgame;

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
	void		*victor_win;
	int			win_width;
	int			win_height;
	int			run;
	t_map		map;
	t_sprite	sprite;
	t_player	player;
	t_endgame	end;
}	t_game;

void	get_map(t_game *var, char *fd_path);
void	map_chars(t_game *var, int fd);
void	map_counters(t_game *var);
void	map_size(t_game *var, int fd);
void	map_walls(t_game *var);
void	path_find(t_game *var);
int		put_error(int error, t_game *var);
void	game_init(t_game *var);
void	img_init(t_game *var);
void	img_addr(t_game *var);
void	img_addr_2(t_game *var);
void	make_map(t_game *var);
void	make_extras(t_game *var, int x, int y);
void	put_tile(t_game *var, t_img *tile, int screen_x, int screen_y);
void	my_pixel_put(t_img *data, int x, int y, int color);
int		keypress(int key, t_game *var);
void	move(t_game *var, int x, int y);
void	coins(t_game *var);
int		destruct(t_game *var);
int		render_frame(t_game *var);
void	end_game(t_game *var);
void	end_img_init(t_game *var);
void	end_animation(t_game *var);
void	end_destruct(t_game *var);

#endif
