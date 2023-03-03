/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:02:20 by mortins-          #+#    #+#             */
/*   Updated: 2023/03/03 19:14:56 by mortins-         ###   ########.fr       */
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

# define SPRITE_SIZE 64

# define KEY_ESC 65307

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

# define PATH_PLAYER_U "sprites/player_u.xpm"
# define PATH_PLAYER_L "sprites/player_l.xpm"
# define PATH_PLAYER_D "sprites/player_d.xpm"
# define PATH_PLAYER_R "sprites/player_r.xpm"
# define PATH_COIN "sprites/coin.xpm"
# define PATH_WALL "sprites/wall.xpm"
# define PATH_FLOOR "sprites/floor.xpm"

typedef struct s_player {
	int		x;
	int		y;
	void	*img;
}	t_player;

typedef struct s_sprite {
	void	*player_up;
	void	*player_left;
	void	*player_down;
	void	*player_right;
	void	*coin;
	void	*wall;
	void	*floor;
	void	*locked;
	void	*unlocked;
	void	*exit;
}	t_sprite;

typedef struct s_map {
	char	**map;
	int		map_y;
	int		c_c;
	int		e_c;
	int		p_c;
}	t_map;

typedef struct s_game {
	void		*mlx;
	void		*win;
	t_map		map;
	t_sprite	sprite;
	t_player	player;
}	t_game;

void	get_map(t_game *var, char *fd_path);
void	copy_map(t_game *var, int fd);
void	check_counters(t_game *var);
void	check_map(t_game *var, int fd);
int		put_error(int error, t_game *var);
void	img_init(t_game *var);
int		keypress(int key, t_game *var);
void	move(t_game *var, char direction);
int		destruct(t_game *var);
int		render_frame(t_game *var);

#endif
