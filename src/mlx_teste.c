/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_teste.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:44:02 by mortins-          #+#    #+#             */
/*   Updated: 2023/03/07 18:52:21 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* #define PATH_CURSOR "sprites/cursor.xpm" */

/* typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		endian;
}	t_img; */

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
/* 	mlx_destroy_image(var->mlx, var->sprite.cursor); */
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

int	render_frame(t_game *var)
{
/* 	int	x = 0;
	int	y = 0; */

	/* while (y < var->win_height)
	{
		while (x < var->win_width)
		{
			mlx_put_image_to_window(var->mlx, var->win, var->sprite.floor.img, x, y);
			x += IMG_SIZE;
		}
		x = 0;
		y += IMG_SIZE;
	} */
	/* if (var->cursor.cursor == 1)
		mlx_put_image_to_window(var->mlx, var->win, var->sprite.cursor, var->cursor.x, var->cursor.y); */
	mlx_put_image_to_window(var->mlx, var->win, var->map.img.img, 0, 0);
	mlx_put_image_to_window(var->mlx, var->win, var->player.img, var->player.x, var->player.y);
	return (0);
}

/*	Calculate Memory Offset to allign bytes
	int offset = (y * length + x * (bpp / 8));
*/

void	my_pixel_put(t_img *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

/* int	grid(t_img *img)
{
	int	x = 0;
	int	y = 64;
	while (y < WIN_HEIGHT)
	{
		while (x < WIN_WIDTH)
		{
			my_pixel_put(img, x, y, 0x00ffffff);
			x++;
		}
		x = 0;
		y += 64;
	}
	x = 64;
	y = 0;
	while (x < WIN_WIDTH)
	{
		while (y < WIN_HEIGHT)
		{
			my_pixel_put(img, x, y, 0x00ffffff);
			y++;
		}
		y = 0;
		x += 64;
	}
	return (0);
} */

/* void	my_diamonds_put(t_img *img, int height)
{
	int	x;
	int	y;
	int	count;
	int	line;

	x = 1;
	y = 2;
	line = 1;
	count = 0;
	while (y < WIN_HEIGHT)
	{
		if (x == WIN_WIDTH)
		{
			x = 1;
			y = (line * height) + 2;
			count = 0;
			line++;
			if (line % 2 == 0)
			{
				count = -height;
				y = (line * height) + 2;
			}
		}
		while (x < WIN_WIDTH  && y < WIN_HEIGHT && (count >= 0 && count < height))
		{
			my_pixel_put(img, x, y, 0x00ffffff);
			x++;
			y++;
			count++;
			if (count == height)
				count = -height;
		}
		while (x < WIN_WIDTH  && y < WIN_HEIGHT && count < 0)
		{
			my_pixel_put(img, x, y, 0x00ffffff);
			x++;
			y--;
			count++;
			if (count == height)
				count = 0;
		}
	}
} */

/* void	my_triangles_put(t_img *img, int height)
{
	int	x;
	int	y;
	int	line;

	x = 0;
	line = 1;
	y = 0;
	my_diamonds_put(img, height);
	while (y < WIN_HEIGHT)
	{
		y = (height * line) + 2;
		while (x < WIN_WIDTH)
		{
			my_pixel_put(img, x, y, 0x00ffffff);
			x++;
		}
		line++;
		x = 0;
	}
} */

/* void	my_border_put(t_img *img, int thick, int color)
{
	int	x;
	int	y;
	int	lines;

	x = 0;
	y = 0;
	lines = 0;
	if (thick > 0)
	{
		while (lines < thick && y < WIN_HEIGHT)
		{
			while (x < WIN_WIDTH)
			{
				my_pixel_put(img, x, y, color);
				my_pixel_put(img, x, (WIN_HEIGHT - y), color);
				x++;
			}
			x = 0;
			y++;
			lines++;
		}
		x = 0;
		y = 0;
		lines = 0;
		while (lines < thick && x < WIN_WIDTH)
		{
			while (y < WIN_HEIGHT)
			{
				my_pixel_put(img, x, y, color);
				my_pixel_put(img, WIN_WIDTH - x, y, color);
				y++;
			}
			y = 0;
			x++;
			lines++;
		}
	}
} */

/* int	join(t_game *var)
{
	var->cursor.cursor = 1;
	ft_printf("hello dear!\n");
	return (0);
} */

/* int	bye(t_game *var)
{
	var->cursor.cursor = 0;
	ft_printf("farewell\n");
	return (0);
} */

/* int	mouse(int button, int x, int y, t_game *var)
{
	if (button == 1)
	{
		if ((x >= var->player.x && x <= (var->player.x + IMG_SIZE)) && (y >= var->player.y && y <= (var->player.y + IMG_SIZE)))
			ft_printf("Ouch!\n");
			destruct(var);
	}
	return (0);
} */

/* int	position(int x, int y, t_game *var)
{
	var->cursor.x = x;
	var->cursor.y = y;
	ft_printf("x: %d   y: %d\n", var->cursor.x, var->cursor.y);
	return (0);
} */

/* void	img_fix(t_data *data, int size, unsigned int del)
{
	int		x = 0;
	int		y = 0;
	char	*color;

	while (y < size)
	{
		while (x < size)
		{
			color = data->addr + (y * data->length + x * (data->bpp / 8));
			if (*(unsigned int*)color == del)
				*(unsigned int*)color = 0x########;
			x++;
		}
		x = 0;
		y++;
	}
} */

void	move(t_game *var, char direction)
{
	if (direction == 'u' && (var->player.y - IMG_SIZE >= 0))
	{
		var->player.moves++;
		var->player.y -= IMG_SIZE;
		ft_printf("Number of moves: %d\n", var->player.moves);
	}
	if (direction == 'l' && (var->player.x - IMG_SIZE >= 0))
	{
		var->player.moves++;
		var->player.x -= IMG_SIZE;
		ft_printf("Number of moves: %d\n", var->player.moves);
	}
	if (direction == 'd' && (var->player.y + (IMG_SIZE * 2) <= var->win_height))
	{
		var->player.moves++;
		var->player.y += IMG_SIZE;
		ft_printf("Number of moves: %d\n", var->player.moves);
	}
	if (direction == 'r' && (var->player.x + (IMG_SIZE * 2) <= var->win_width))
	{
		var->player.moves++;
		var->player.x += IMG_SIZE;
		ft_printf("Number of moves: %d\n", var->player.moves);
	}
}

int	keypress(int key, t_game *var)
{
	if (key == KEY_ESC)
		destruct(var);
	if (key == KEY_W || key == KEY_UP)
	{
		var->player.img = var->sprite.player_up;
		move(var, 'u');
	}
	if (key == KEY_A || key == KEY_LEFT)
	{
		var->player.img = var->sprite.player_left;
		move(var, 'l');
	}
	if (key == KEY_S || key == KEY_DOWN)
	{
		var->player.img = var->sprite.player_down;
		move(var, 'd');
	}
	if (key == KEY_D || key == KEY_RIGHT)
	{
		var->player.img = var->sprite.player_right;
		move(var, 'r');
	}
	return (0);
}

/* void	img_addr(t_game *var)
{
	var->player.img.addr = mlx_get_data_addr(var->player.img.img, &var->player.img.bpp, &var->player.img.length, &var->player.img.endian);
	img_fix(var, &var->player.img, IMG_SIZE, 0x0000FF1F);
} */

int	main(int argc, char **argv)
{
	t_game	var;

	if (argc != 2)
		put_error(0, &var);
	get_map(&var, argv[1]);
	var.mlx = mlx_init();
	if (var.mlx == NULL)
		return (put_error(7, &var));
	var.win = mlx_new_window(var.mlx, var.win_width, var.win_height, "teste");
	if (var.win == NULL)
		put_error(8, &var);
	/*var.sprite.wall.img = mlx_new_image(var.mlx, IMG_SIZE, IMG_SIZE);
		var.sprite.wall.addr = mlx_get_data_addr(var.sprite.wall.img, &var.sprite.wall.bpp, &var.sprite.wall.length, &var.sprite.wall.endian); */
	game_init(&var);
	/*img_addr(&var);*/
	/* my_diamonds_put(&var.img, 20);
		my_triangles_put(&var.img, 40);
		my_border_put(&var.img, 1, 0x00ffffff);
		grid(&var.img); */
	mlx_hook(var.win, 2, 1L<<0, keypress, &var);
	mlx_hook(var.win, 17, 0L, destruct, &var);
	/* mlx_hook(var.win, 4, 1L<<2, mouse, &var); */
	/* mlx_hook(var.win, 6, 1L<<6, position, &var);
		mlx_hook(var.win, 7, 1L<<4, join, &var);
		mlx_hook(var.win, 8, 1L<<5, bye, &var); */
	mlx_loop_hook(var.mlx, render_frame, &var);
	mlx_loop(var.mlx);
}
