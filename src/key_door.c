/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_door.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanghyki <kanghyki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:24:28 by kanghyki          #+#    #+#             */
/*   Updated: 2022/12/13 13:05:30 by kanghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static bool	is_not_empty(int where);
static int	ft_abs(int num);

void	interact_door(t_info *info)
{
	int	what;
	int	*where;

	calc_vector(info, WIDTH / 2);
	calc_step(info);
	calc_ray_until_hit(info, is_not_empty);
	what = info->raycast.hit_stuff;
	if ((what == DOOR_CLOSE || what == DOOR_OPEN)
		&& (ft_abs(info->pos_x - info->raycast.map_x) < 2
			&& ft_abs(info->pos_y - info->raycast.map_y) < 2))
	{
		where = &info->map.map[info->raycast.map_y][info->raycast.map_x];
		if (what == DOOR_CLOSE)
			*where = DOOR_OPEN;
		else
			*where = DOOR_CLOSE;
	}
}

static bool	is_not_empty(int where)
{
	if (where != EMPTY)
		return (true);
	return (false);
}

static int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}
