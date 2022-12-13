/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:48:03 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/13 13:48:56 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	set_dir_ns(t_info *info, int dir)
{
	if (dir == S)
	{
		info->dir_x = 0.0;
		info->dir_y = -1.0;
		info->plane_x = 0.66;
		info->plane_y = 0.0;
	}
	else if (dir == N)
	{
		info->dir_x = 0.0;
		info->dir_y = 1.0;
		info->plane_x = -0.66;
		info->plane_y = 0.0;
	}
}

static void	set_dir_ew(t_info *info, int dir)
{
	if (dir == E)
	{
		info->dir_x = 0.0;
		info->dir_y = 1.0;
		info->plane_x = -0.66;
		info->plane_y = 0.0;
	}
	else if (dir == W)
	{
		info->dir_x = -1.0;
		info->dir_y = 0.0;
		info->plane_x = 0.0;
		info->plane_y = -0.6;
	}
}

void	set_dir(t_info *info, int dir)
{
	if (dir == E || dir == W)
		set_dir_ew(info, dir);
	else
		set_dir_ns(info, dir);
}
