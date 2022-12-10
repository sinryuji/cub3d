/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:23:33 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/10 21:20:29 by kanghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	g_world_map[MAP_WIDTH][MAP_HEIGHT] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

static void	info_init(t_info *info)
{
	int	i;

	info->mlx = mlx_init();
	info->pos_x = 3.0;
	info->pos_y = 3.0;
	info->dir_x = 0.0;
	info->dir_y = 1.0;
	info->plane_x = -0.66;
	info->plane_y = 0.0;
	info->move_speed = 0.25;
	info->rot_speed = 0.1;
	info->mouse_speed = 0.03;
	info->buf = (int **)malloc(sizeof(int *) * HEIGHT);
	i = 0;
	while (i < HEIGHT)
		info->buf[i++] = (int *)ft_calloc(WIDTH, sizeof(int));
	info->texture = (int **)malloc(sizeof(int *) * TEXTURE_COUNT);
	i = 0;
	while (i < TEXTURE_COUNT)
		info->texture[i++] = (int *)ft_calloc((TEX_WIDTH * TEX_HEIGHT), sizeof(int));
//	ft_memset(&info->raycast, 0, sizeof(t_raycast));
//	ft_memset(&info->draw, 0, sizeof(t_draw));
}

static void	draw(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			info->img.data[y * WIDTH + x] = info->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void load_xpm(t_info *info, int *texture, char *path, t_img *img)
{
	int	x;
	int	y;
	img->img_width = TEX_WIDTH;
	img->img_height = TEX_HEIGHT;

	img->img = mlx_xpm_file_to_image(info->mlx, path,\
			&img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp,\
			&img->size_line, &img->endian);
	y = 0;
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = \
				img->data[img->img_width * y + x];
			++x;
		}
		++y;
	}
	mlx_destroy_image(info->mlx, img->img);
}

void load_texture(t_info *info)
{
	t_img img;

	load_xpm(info, info->texture[NORTH], "textures/north.xpm", &img);
	load_xpm(info, info->texture[SOUTH], "textures/south.xpm", &img);
	load_xpm(info, info->texture[WEST], "textures/east.xpm", &img);
	load_xpm(info, info->texture[EAST], "textures/west.xpm", &img);
}

static int	main_loop(t_info *info)
{
	calc(info);
	draw(info);
	draw_minimap(info);
	return (EXIT_SUCCESS);
}

int	main(void)
{
	t_info	info;

	info_init(&info);
	load_texture(&info);
	info.win = mlx_new_window(info.mlx, WIDTH, HEIGHT, "cub3d");
	info.img.img = mlx_new_image(info.mlx, WIDTH, HEIGHT);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, \
			&info.img.bpp, &info.img.size_line, &info.img.endian);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X11_KEY_PRESS, 0, key_hook, &info);
	mlx_hook(info.win, X11_WIN_DESTROY, 0, exit_hook, &info);
	mlx_hook(info.win, X11_MOUSE_MOVE, 0, mouse_move, &info);
	mlx_loop(info.mlx);
	return (EXIT_SUCCESS);
}
