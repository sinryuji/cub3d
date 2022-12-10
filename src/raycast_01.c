/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:43:43 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/10 23:19:42 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	calc_step(t_info *info)
{
	if (info->raycast.ray_dir_x < 0)
	{
		info->raycast.step_x = -1;
		info->raycast.side_dist_x = (info->pos_x - info->raycast.map_x) * \
									info->raycast.delta_dist_x;
	}
	else
	{
		info->raycast.step_x = 1;
		info->raycast.side_dist_x = (info->raycast.map_x + 1.0 - info->pos_x) * \
									info->raycast.delta_dist_x;
	}
	if (info->raycast.ray_dir_y < 0)
	{
		info->raycast.step_y = -1;
		info->raycast.side_dist_y = (info->pos_y - info->raycast.map_y) * \
									info->raycast.delta_dist_y;
	}
	else
	{
		info->raycast.step_y = 1;
		info->raycast.side_dist_y = (info->raycast.map_y + 1.0 - info->pos_y) * \
									info->raycast.delta_dist_y;
	}
}

static void	calc_vector(t_info *info, int x)
{
	info->raycast.camera_x = (2 * x / (double)WIDTH) - 1;
	info->raycast.ray_dir_x = info->dir_x + info->plane_x * \
								info->raycast.camera_x;
	info->raycast.ray_dir_y = info->dir_y + info->plane_y * \
								info->raycast.camera_x;
	info->raycast.map_x = (int)info->pos_x;
	info->raycast.map_y = (int)info->pos_y;
	info->raycast.delta_dist_x = fabs(1 / info->raycast.ray_dir_x);
	info->raycast.delta_dist_y = fabs(1 / info->raycast.ray_dir_y);
}

static void	calc_dist(t_info *info)
{
	info->raycast.hit = 0;
	while (info->raycast.hit == 0)
	{
		if (info->raycast.side_dist_x < info->raycast.side_dist_y)
		{
			info->raycast.side_dist_x += info->raycast.delta_dist_x;
			info->raycast.map_x += info->raycast.step_x;
			info->raycast.side = 0;
		}
		else
		{
			info->raycast.side_dist_y += info->raycast.delta_dist_y;
			info->raycast.map_y += info->raycast.step_y;
			info->raycast.side = 1;
		}
		if (g_world_map[info->raycast.map_y][info->raycast.map_x] > 0)
			info->raycast.hit = 1;
	}
	if (info->raycast.side == 0)
		info->raycast.perp_wall_dist = (info->raycast.map_x - info->pos_x + \
				(1.0 - info->raycast.step_x) / 2) / info->raycast.ray_dir_x;
	else
		info->raycast.perp_wall_dist = (info->raycast.map_y - info->pos_y + \
				(1.0 - info->raycast.step_y) / 2) / info->raycast.ray_dir_y;
}

static void	calc_draw(t_info *info)
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

void	calc(t_info *info)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		calc_vector(info, x);
		calc_step(info);
		calc_dist(info);
		calc_draw(info);
		calc_texture(info, x);
		++x;
	}
}
