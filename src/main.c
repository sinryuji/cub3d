/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:23:33 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/09 18:38:54 by kanghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	info->move_speed = 0.5;
	info->rot_speed = 0.1;
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

void draw_minimap(t_info *info)
{
	int minimap_height = HEIGHT / 5;
	int minimap_width = WIDTH / 5;
	info->img.img = mlx_new_image(info->mlx, minimap_width, minimap_height);
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp, &info->img.size_line, &info->img.endian);

	for(int y = 0; y < minimap_height; y++)
		for(int x = 0; x < minimap_width; x++)
			info->img.data[y * minimap_width+ x] = 0;

	int temp = g_world_map[(int)(info->pos_y - 1)][(int)(info->pos_x - 1)];
	g_world_map[(int)(info->pos_y - 1)][(int)(info->pos_x - 1)] = 2;
	for(int y = 0; y < minimap_height; y++)
	{
		for(int x = 0; x < minimap_width; x++)
		{
			double y_ratio = (double)y / minimap_height;
			double x_ratio = (double)x / minimap_width;
			if (g_world_map[(int)(y_ratio * MAP_HEIGHT)][(int)(x_ratio * MAP_WIDTH)] == 1)
			{
				info->img.data[y * minimap_width + x] = 0x98c379;
			}
			if (g_world_map[(int)(y_ratio * MAP_HEIGHT)][(int)(x_ratio * MAP_WIDTH)] == 2)
			{
				info->img.data[y * minimap_width + x] = 0xe5c07b;
			}
		}
	}
	g_world_map[(int)(info->pos_y - 1)][(int)(info->pos_x - 1)] = temp;

	for(int x = 0; x < WIDTH; x++)
	{
		double camera_x = (2 * x / (double)WIDTH) - 1;
		double rayDir_x = info->dir_x + info->plane_x * camera_x;
		double rayDir_y = info->dir_y + info->plane_y * camera_x;

		int map_x = (int)info->pos_x;
		int map_y = (int)info->pos_y;

		double deltaDist_x = fabs(1 / rayDir_x);
		double deltaDist_y = fabs(1 / rayDir_y);

		int step_x;
		int step_y;
		double sideDist_x;
		double sideDist_y;
		if (rayDir_x < 0)
		{
			step_x = -1;
			sideDist_x = (info->pos_x - map_x) * deltaDist_x;
		}
		else
		{
			step_x = 1;
			sideDist_x = (map_x + 1.0 - info->pos_x) * deltaDist_x;
		}
		if (rayDir_y < 0)
		{
			step_y = -1;
			sideDist_y = (info->pos_y - map_y) * deltaDist_y;
		}
		else
		{
			step_y = 1;
			sideDist_y = (map_y + 1.0 - info->pos_y) * deltaDist_y;
		}


		int hit = 0;
		while (hit == 0)
		{
			double yy = (double)map_y / MAP_HEIGHT * minimap_height;
			double xx = (double)map_x / MAP_WIDTH * minimap_width;

			info->img.data[(int)(yy * minimap_width + xx)] = 0xc678dd;
			if (sideDist_x < sideDist_y)
			{
				sideDist_x += deltaDist_x;
				map_x += step_x;
			}
			else
			{
				sideDist_y += deltaDist_y;
				map_y += step_y;
			}
			if (g_world_map[map_y][map_x] > 0) hit = 1;
		}
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 5, 5);
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
//	draw_minimap(&info);
	mlx_loop(info.mlx);
	return (EXIT_SUCCESS);
}
