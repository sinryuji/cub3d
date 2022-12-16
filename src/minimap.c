/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanghyki <kanghyki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:39:49 by kanghyki          #+#    #+#             */
/*   Updated: 2022/12/16 21:43:24 by kanghyki         ###   ########.fr       */
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
	int const	max_range = 10;

	info->minimap.ratio = (double)MM_RADIUS * 2 / max_range;
	info->minimap.img.img = mlx_new_image(info->mlx, \
			MM_RADIUS * 2, MM_RADIUS * 2);
	info->minimap.img.data = (int *)mlx_get_data_addr(\
			info->minimap.img.img, \
			&info->minimap.img.bpp, \
			&info->minimap.img.size_line, \
			&info->minimap.img.endian);
}

void	put_minimap(t_info *info)
{
	int	x;
	int	y;
	int	*data;

	y = -MM_RADIUS;
	while (y < MM_RADIUS)
	{
		x = -MM_RADIUS;
		while (x < MM_RADIUS)
		{
			data = &info->minimap.img.data \
				[(y + MM_RADIUS) *(MM_RADIUS * 2) + (x + MM_RADIUS)];
			if (((x * x) + (y * y)) <= MM_RADIUS * MM_RADIUS)
				*data = get_minimap_color(info, x + MM_RADIUS, y + MM_RADIUS);
			else
				*data = MM_EMPTY;
			++x;
		}
		++y;
	}
}

static int	get_minimap_color(t_info *info, int x, int y)
{
	int		what;
	double	pos_y;
	double	pos_x;

	pos_y = y / info->minimap.ratio + \
			info->pos_y - ((MM_RADIUS * 2 / info->minimap.ratio) / 2);
	pos_x = x / info->minimap.ratio + \
			info->pos_x - ((MM_RADIUS * 2 / info->minimap.ratio) / 2);
	if (pos_y < 0 || pos_y >= info->map.height)
		what = WALL;
	else if (pos_x < 0 || pos_x >= info->map.width)
		what = WALL;
	else
		what = info->map.map[(int)pos_y][(int)pos_x];
	if ((int)info->pos_y == (int)pos_y && (int)info->pos_x == (int)pos_x)
		return (MM_PLAYER_COLOR);
	else if (what == TARGET)
		return (MM_TARGET_COLOR);
	else if (what == DOOR_OPEN)
		return (MM_DOOR_OPEN_COLOR);
	else if (what == DOOR_CLOSE)
		return (MM_DOOR_CLOSE_COLOR);
	else if (what == WALL)
		return (MM_WALL_COLOR);
	return (MM_BG_COLOR);
}

void	put_image_to_mlx(t_info *info)
{
	mlx_put_image_to_window(\
			info->mlx, info->win, info->minimap.img.img, 10, 10);
}
