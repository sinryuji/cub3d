/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:23:33 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/07 22:31:49 by hyeongki         ###   ########.fr       */
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
	info->plane_x = 0.66;
	info->plane_y = 0.0;
	info->move_speed = 0.5;
	info->rot_speed = 0.1;
	info->buf = (int **)malloc(sizeof(int *) * HEIGHT);
	i = 0;
	while (i < HEIGHT)
		info->buf[i++] = (int *)malloc(sizeof(int) * WIDTH);
	ft_memset(info->buf, 0, WIDTH * HEIGHT);
	info->texture = (int **)malloc(sizeof(int *) * 4);
	i = 0;
	while (i < 4)
		info->texture[i++] = (int *)malloc(sizeof(int) * \
				(TEX_WIDTH * TEX_HEIGHT));
	ft_memset(info->texture, 0, TEX_WIDTH * TEX_HEIGHT * 4);
	ft_memset(&info->raycast, 0, sizeof(t_raycast));
	ft_memset(&info->draw, 0, sizeof(t_draw));
}

static void	draw(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while ( x < WIDTH)
		{
			info->img.data[y * WIDTH + x] = info->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

static int	main_loop(t_info *info)
{
	printf("1\n");
	calc(info);
	printf("2\n");
	draw(info);
	printf("3\n");
	return (EXIT_SUCCESS);
}

int	main(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	info_init(info);
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "cub3d");
	printf("1\n");
	info->img.img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	printf("1\n");
	info->img.data = (int *)mlx_get_data_addr(info->img.img, \
			&info->img.bpp, &info->img.sizeLine, &info->img.endian);
	printf("1\n");
	mlx_loop_hook(info->mlx, &main_loop, info);
	mlx_loop(info->mlx);
	return (EXIT_SUCCESS);
}
