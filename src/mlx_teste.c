/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_teste.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortins- <mortins-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:44:02 by mortins-          #+#    #+#             */
/*   Updated: 2023/03/01 17:24:35 by mortins-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define WIN_WIDTH 1408
#define WIN_HEIGHT 896

/* #define PATH_CURSOR "sprites/cursor.xpm" */

/* typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		endian;
}	t_img; */

/*	Calculate Memory Offset to allign bytes
	int offset = (y * length + x * (bpp / 8));
*/

int	destruct(t_game *var)
{
	mlx_destroy_image(var->mlx, var->sprite.floor);
	mlx_destroy_image(var->mlx, var->sprite.player_up);
	mlx_destroy_image(var->mlx, var->sprite.player_left);
	mlx_destroy_image(var->mlx, var->sprite.player_down);
	mlx_destroy_image(var->mlx, var->sprite.player_right);
/* 	mlx_destroy_image(var->mlx, var->sprite.cursor); */
	mlx_destroy_image(var->mlx, var->player.img);
	mlx_clear_window(var->mlx, var->win);
	mlx_destroy_window(var->mlx, var->win);
	mlx_destroy_display(var->mlx);
	free(var->mlx);
	exit (0);
	return (0);
}

int put_error(int n, t_game *var)
{
	if (n == 1)
		ft_printf("Error\nFailed to initiate mlx.");
	if (n == 2)
		ft_printf("Error\nFailed to create a new window.");
	destruct(var);
	return (0);
}

int	render_frame(t_game *var)
{
	int	x = 0;
	int	y = 0;

	while (x < WIN_WIDTH && y < WIN_HEIGHT)
	{
		while (x < WIN_WIDTH)
		{
			mlx_put_image_to_window(var->mlx, var->win, var->sprite.floor, x, y);
			x += SPRITE_SIZE;
		}
		x = 0;
		y += SPRITE_SIZE;
	}
	/* if (var->cursor.cursor == 1)
		mlx_put_image_to_window(var->mlx, var->win, var->sprite.cursor, var->cursor.x, var->cursor.y); */
	mlx_put_image_to_window(var->mlx, var->win, var->player.img, var->player.x, var->player.y);
	return (0);
}

/* void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
} */

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

int	mouse(int button, int x, int y, t_game *var)
{
	if (button == 1)
	{
		if ((x >= var->player.x && x <= (var->player.x + SPRITE_SIZE)) && (y >= var->player.y && y <= (var->player.y + SPRITE_SIZE)))
			ft_printf("Ouch!\n");
			/* destruct(var); */
	}
	return (0);
}

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

int	keypress(int key, t_game *var)
{
	if (key == KEY_ESC)
		destruct(var);
	if ((key == KEY_W || key == KEY_UP) && (var->player.y - SPRITE_SIZE >= 0))
	{
		var->player.y -= SPRITE_SIZE;
		var->player.img = var->sprite.player_up;
	}
	if ((key == KEY_A || key == KEY_LEFT) && (var->player.x - SPRITE_SIZE >= 0))
	{
		var->player.x -= SPRITE_SIZE;
		var->player.img = var->sprite.player_left;
	}
	if ((key == KEY_S || key == KEY_DOWN) && (var->player.y + (SPRITE_SIZE * 2) <= WIN_HEIGHT))
	{
		var->player.y += SPRITE_SIZE;
		var->player.img = var->sprite.player_down;

	}
	if ((key == KEY_D || key == KEY_RIGHT) && (var->player.x + (SPRITE_SIZE * 2) <= WIN_WIDTH))
	{
		var->player.x += SPRITE_SIZE;
		var->player.img = var->sprite.player_right;
	}
	return (0);
}

void	img_init(t_game *var)
{
	int	i = SPRITE_SIZE;
	/* int	j = 36; */

	var->sprite.floor = mlx_xpm_file_to_image(var->mlx, PATH_FLOOR, &i, &i);
	var->sprite.player_up = mlx_xpm_file_to_image(var->mlx, PATH_PLAYER_U, &i, &i);
	var->sprite.player_left = mlx_xpm_file_to_image(var->mlx, PATH_PLAYER_L, &i, &i);
	var->sprite.player_down = mlx_xpm_file_to_image(var->mlx, PATH_PLAYER_D, &i, &i);
	var->sprite.player_right = mlx_xpm_file_to_image(var->mlx, PATH_PLAYER_R, &i, &i);
	var->player.img = var->sprite.player_down;
	/* var->sprite.cursor = mlx_xpm_file_to_image(var->mlx, PATH_CURSOR , &j, &j); */
}

/* void	img_addr(t_game *var)
{
	var->player.img.addr = mlx_get_data_addr(var->player.img.img, &var->player.img.bpp, &var->player.img.length, &var->player.img.endian);
	img_fix(var, &var->player.img, SPRITE_SIZE, 0x0000FF1F);
} */

int	main(void)
{
	t_game	var;

	var.mlx = mlx_init();
	if (var.mlx == NULL)
		return (put_error(1, &var));
	var.win = mlx_new_window(var.mlx, WIN_WIDTH, WIN_HEIGHT, "teste");
	if (var.win == NULL)
	{
		free (var.win);
		return (put_error(2, &var));
	}
/* 	var.sprite.wall.img = mlx_new_image(var.mlx, SPRITE_SIZE, SPRITE_SIZE);
	var.sprite.wall.addr = mlx_get_data_addr(var.sprite.wall.img, &var.sprite.wall.bpp, &var.sprite.wall.length, &var.sprite.wall.endian); */
	img_init(&var);
/* 	img_addr(&var); */
	var.player.x = 0;
	var.player.y = 0;
	/* my_diamonds_put(&var.img, 20); */
	/* my_triangles_put(&var.img, 40); */
	/* my_border_put(&var.img, 1, 0x00ffffff); */
	/* grid(&var.img); */
	mlx_hook(var.win, 2, 1L<<0, keypress, &var);
	mlx_hook(var.win, 17, 0L, destruct, &var);
	/* mlx_hook(var.win, 4, 1L<<2, mouse, &var); */
/* 	mlx_hook(var.win, 6, 1L<<6, position, &var); */
/* 	mlx_hook(var.win, 7, 1L<<4, join, &var);
	mlx_hook(var.win, 8, 1L<<5, bye, &var); */
	mlx_loop_hook(var.mlx, render_frame, &var);
	mlx_loop(var.mlx);
}
