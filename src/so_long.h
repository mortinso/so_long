/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:02:20 by mortins-          #+#    #+#             */
/*   Updated: 2023/03/24 16:03:51 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../utils/ft_printf/ft_printf.h"
# include "../utils/get_next_line/get_next_line.h"
# include "../utils/libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

# define IMG_SIZE 48

# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

# define GREEN_SCREEN 0x00dc00ff

# define PLAYER_U "sprites/game/player_u.xpm"
# define PLAYER_L "sprites/game/player_l.xpm"
# define PLAYER_D "sprites/game/player_d.xpm"
# define PLAYER_R "sprites/game/player_r.xpm"
# define COIN "sprites/game/coin.xpm"
# define WALL "sprites/game/wall.xpm"
# define FLOOR "sprites/game/floor.xpm"
# define LOCK "sprites/game/locked.xpm"
# define UNLOCK "sprites/game/unlocked.xpm"
# define COUNTER "sprites/game/counter.xpm"

# define PLAYER_U1 "sprites/animations/player_u1.xpm"
# define PLAYER_U2 "sprites/animations/player_u2.xpm"
# define PLAYER_L1 "sprites/animations/player_l1.xpm"
# define PLAYER_L2 "sprites/animations/player_l2.xpm"
# define PLAYER_D1 "sprites/animations/player_d1.xpm"
# define PLAYER_D2 "sprites/animations/player_d2.xpm"
# define PLAYER_R1 "sprites/animations/player_r1.xpm"
# define PLAYER_R2 "sprites/animations/player_r2.xpm"

# define BREAK_1 "sprites/animations/breaking_1.xpm"
# define BREAK_2 "sprites/animations/breaking_2.xpm"
# define BREAK_3 "sprites/animations/breaking_3.xpm"

# define END_SCREEN "sprites/game/screen.xpm"
# define END_1 "sprites/animations/bike1.xpm"
# define END_2 "sprites/animations/bike2.xpm"
# define END_3 "sprites/animations/bike3.xpm"
# define END_4 "sprites/animations/bike4.xpm"
# define END_5 "sprites/animations/bike5.xpm"
# define END_6 "sprites/animations/bike6.xpm"

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		endian;
}	t_img;

typedef struct s_player {
	t_img	img;
	t_img	move1;
	t_img	move2;
	int		dir_x;
	int		dir_y;
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
	t_img	counter;
	t_img	wall;
	t_img	floor;
	t_img	lock;
	t_img	break_1;
	t_img	break_2;
	t_img	break_3;
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
	int			moving;
	int			unlocking;
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
void	get_positions(t_game *var);
void	path_find(t_game *var, int x, int y);
void	path_check(t_game *var);
int		put_error(int error, t_game *var);
int		put_error2(int error, t_game *var);
void	game_init(t_game *var);
void	img_init(t_game *var);
void	img_init2(t_game *var);
void	img_addr(t_game *var);
void	img_addr_2(t_game *var);
void	put_tile(t_game *var, t_img *tile, int screen_x, int screen_y);
void	put_move_counter(t_game *var);
void	my_pixel_put(t_img *data, int x, int y, int color);
void	make_map(t_game *var);
int		render_frame(t_game *var);
int		keypress(int key, t_game *var);
void	move(t_game *var, int x, int y);
void	coins(t_game *var);
int		destruct(t_game *var);
void	end_game(t_game *var);
void	end_img_init(t_game *var);
void	end_destruct(t_game *var);
void	end_animation(t_game *var);
void	unlock_animation(t_game *var);

#endif
