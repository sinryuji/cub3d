/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_pistol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanghyki <kanghyki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:04:40 by kanghyki          #+#    #+#             */
/*   Updated: 2022/12/14 13:05:14 by kanghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static bool	is_not_empty(int where);

void	shoot_pistol(t_info *info)
{
	int	what;

	calc_vector(info, WIDTH / 2);
	calc_step(info);
	calc_ray_until_hit(info, is_not_empty);
	what = info->raycast.hit_stuff;
	if (what == TARGET)
		info->map.map[info->raycast.map_y][info->raycast.map_x] = WALL;
}

static bool	is_not_empty(int where)
{
	if (where != EMPTY)
		return (true);
	return (false);
}
