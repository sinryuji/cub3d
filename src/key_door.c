/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_door.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanghyki <kanghyki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:24:28 by kanghyki          #+#    #+#             */
/*   Updated: 2022/12/12 15:27:44 by kanghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	hit_what(t_info *info);
static int	ft_abs(int num);

void	interact_door(t_info *info)
{
	int	what;
	int	*where;

	calc_vector(info, WIDTH / 2);
	calc_step(info);
	what = hit_what(info);
	if ((what == DOOR_CLOSE || what == DOOR_OPEN)
		&& (ft_abs(info->pos_x - info->raycast.map_x) < 2
			&& ft_abs(info->pos_y - info->raycast.map_y) < 2))
	{
		where = &g_world_map[info->raycast.map_y][info->raycast.map_x];
		if (what == DOOR_CLOSE)
			*where = DOOR_OPEN;
		else
			*where = DOOR_CLOSE;
	}
}

static int	hit_what(t_info *info)
{
	info->raycast.hit = false;
	while (info->raycast.hit == false)
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
		if (g_world_map[info->raycast.map_y][info->raycast.map_x] != EMPTY)
			info->raycast.hit = true;
	}
	return (g_world_map[info->raycast.map_y][info->raycast.map_x]);
}

static int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}
