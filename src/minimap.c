/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanghyki <kanghyki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:39:49 by kanghyki          #+#    #+#             */
/*   Updated: 2022/12/10 21:20:44 by kanghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void			init_minimap(t_info *info);
void			put_minimap(t_info *info);
static int		get_minimap_color(t_info *info, int x, int y);
void			put_image_to_mlx(t_info *info);

void	draw_minimap(t_info *info)
{
	init_minimap(info);
	put_minimap(info);
	put_image_to_mlx(info);
}

void	init_minimap(t_info *info)
{
//	info->minimap.range = 10;
	info->minimap.y_ratio = (double)MAP_HEIGHT / MINIMAP_HEIGHT;
	info->minimap.x_ratio = (double)MAP_WIDTH / MINIMAP_WIDTH;
	info->minimap.img.img = mlx_new_image(info->mlx, \
			MINIMAP_WIDTH, MINIMAP_HEIGHT);
	info->minimap.img.data = (int *)mlx_get_data_addr(info->minimap.img.img, \
			&info->img.bpp, &info->img.size_line, &info->img.endian);
}

void	put_minimap(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < MINIMAP_HEIGHT)
	{
		x = 0;
		while (x < MINIMAP_WIDTH)
		{
			info->minimap.img.data[y * MINIMAP_WIDTH + x] = \
												get_minimap_color(info, x, y);
			++x;
		}
		++y;
	}
}

static int	get_minimap_color(t_info *info, int x, int y)
{
	int	what;

	what = g_world_map \
		   [(int)(y * info->minimap.y_ratio)] \
		   [(int)(x * info->minimap.x_ratio)];
	if (what == WALL)
		return (MINIMAP_WALL_COLOR);
	else if ((int)info->pos_y == (int)(y * info->minimap.y_ratio) &&
			(int)info->pos_x == (int)(x * info->minimap.x_ratio))
		return (MINIMAP_PLAYER_COLOR);
	return (MINIMAP_BG_COLOR);
}

void	put_image_to_mlx(t_info *info)
{
	mlx_put_image_to_window(info->mlx, info->win, info->minimap.img.img, 5, 5);
}
