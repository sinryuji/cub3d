/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:43:43 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/14 12:51:14 by kanghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static bool	is_watchable(int where);

void	calc(t_info *info)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		calc_vector(info, x);
		calc_step(info);
		calc_ray_until_hit(info, is_watchable);
		calc_perp_wall_dist(info);
		calc_draw_info(info);
		calc_texture(info, x);
		++x;
	}
}

void	calc_step(t_info *info)
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

void	calc_vector(t_info *info, int x)
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

void	calc_ray_until_hit(t_info *info, bool(*condition)(int))
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
		if (condition(info->map.map[info->raycast.map_y][info->raycast.map_x]))
		{
			info->raycast.hit = 1;
			info->raycast.hit_stuff = \
				info->map.map[info->raycast.map_y][info->raycast.map_x];
		}
	}
}

static bool	is_watchable(int where)
{
	if (where == WALL
		|| where == DOOR_CLOSE
		|| where == TARGET)
		return (true);
	return (false);
}
