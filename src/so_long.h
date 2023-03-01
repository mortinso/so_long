#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../utils/ft_printf/ft_printf.h"
# include "../utils/get_next_line/get_next_line.h"
# include <stdlib.h>

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

# define PATH_BALL "sprites/ball.xpm"
# define PATH_FLOOR "sprites/floor.xpm"

typedef struct s_player {
	int		x;
	int		y;
	void	*img;
}	t_player;

typedef struct s_sprite {
	void	*wall;
	void	*floor;
	void	*exit;
	void	*coin;
	void	*guy_up;
	void	*guy_left;
	void	*guy_down;
	void	*guy_right;
}	t_sprite;

typedef struct s_game {
	void		*mlx;
	void		*win;
	t_sprite	sprite;
	t_player	player;
}	t_game;

int		put_error(int n, t_game *var);
int		keypress(int key, t_game *var);
int		destruct(t_game *var);

#endif
