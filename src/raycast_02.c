/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:44:07 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/12 16:09:36 by kanghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	get_wall_texture_color(t_info *info, int index);

void	calc_perp_wall_dist(t_info *info)
{
	if (info->raycast.side == 0)
		info->raycast.perp_wall_dist = (info->raycast.map_x - info->pos_x + \
				(1.0 - info->raycast.step_x) / 2) / info->raycast.ray_dir_x;
	else
		info->raycast.perp_wall_dist = (info->raycast.map_y - info->pos_y + \
				(1.0 - info->raycast.step_y) / 2) / info->raycast.ray_dir_y;
}

void	calc_draw_info(t_info *info)
{
	info->draw.line_height = (int)(HEIGHT / info->raycast.perp_wall_dist);
	info->draw.draw_start = -info->draw.line_height / 2 + HEIGHT / 2;
	if (info->draw.draw_start < 0)
		info->draw.draw_start = 0;
	info->draw.draw_end = info->draw.line_height / 2 + HEIGHT / 2;
	if (info->draw.draw_end >= HEIGHT)
		info->draw.draw_end = HEIGHT - 1;
	if (info->raycast.side == 0)
		info->draw.wall_x = info->pos_y + \
		info->raycast.perp_wall_dist * info->raycast.ray_dir_y;
	else
		info->draw.wall_x = info->pos_x + \
		info->raycast.perp_wall_dist * info->raycast.ray_dir_x;
	info->draw.wall_x -= floor(info->draw.wall_x);
	info->draw.tex_x = (int)(info->draw.wall_x * (double)WALL_TEX_WIDTH);
	if ((info->raycast.side == 0 && info->raycast.ray_dir_x < 0) || \
			(info->raycast.side == 1 && info->raycast.ray_dir_y > 0))
		info->draw.tex_x = WALL_TEX_WIDTH - info->draw.tex_x - 1;
	info->draw.step = 1.0 * WALL_TEX_HEIGHT / info->draw.line_height;
	info->draw.tex_pos = (info->draw.draw_start - \
	HEIGHT / 2.0 + info->draw.line_height / 2.0) * info->draw.step;
}

void	calc_texture(t_info *info, int x)
{
	int	y;
	int	index;

	y = 0;
	while (y < HEIGHT)
	{
		if (y >= info->draw.draw_start && y < info->draw.draw_end)
		{
			info->draw.tex_y = (int)info->draw.tex_pos & (WALL_TEX_HEIGHT - 1);
			info->draw.tex_pos += info->draw.step;
			index = info->draw.tex_y * WALL_TEX_WIDTH + info->draw.tex_x;
			info->buf[y][x] = get_wall_texture_color(info, index);
		}	
		else if (y < info->draw.draw_start)
			info->buf[y][x] = CEILING_COLOR;
		else
			info->buf[y][x] = FLOOR_COLOR;
		++y;
	}
}

static int	get_wall_texture_color(t_info *info, int index)
{
	int	ret;

	ret = 0;
	if (info->raycast.hit_stuff == DOOR_CLOSE)
		ret = info->texture.wall[T_CLOSE][index];
	else if (info->raycast.hit_stuff == DOOR_OPEN)
		ret = info->texture.wall[T_NORTH][index];
	else if (info->raycast.side == 1 && info->raycast.step_y == 1)
		ret = info->texture.wall[T_NORTH][index];
	else if (info->raycast.side == 1 && info->raycast.step_y == -1)
		ret = info->texture.wall[T_SOUTH][index];
	else if (info->raycast.side == 0 && info->raycast.step_x == 1)
		ret = info->texture.wall[T_EAST][index];
	else if (info->raycast.side == 0 && info->raycast.step_x == -1)
		ret = info->texture.wall[T_WEST][index];
	return (ret);
}
