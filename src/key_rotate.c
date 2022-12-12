/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanghyki <kanghyki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:53:23 by kanghyki          #+#    #+#             */
/*   Updated: 2022/12/12 15:53:55 by kanghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	key_rotate(int key_code, t_info *info, \
		double old_dir_x, double old_plane_x)
{
	if (key_code == KEY_LEFT)
	{
		info->dir_x = info->dir_x * cos(-info->rot_speed) - \
						info->dir_y * sin(-info->rot_speed);
		info->dir_y = old_dir_x * sin(-info->rot_speed) + \
						info->dir_y * cos(-info->rot_speed);
		info->plane_x = info->plane_x * cos(-info->rot_speed) - \
						info->plane_y * sin(-info->rot_speed);
		info->plane_y = old_plane_x * sin(-info->rot_speed) + \
						info->plane_y * cos(-info->rot_speed);
	}
	else if (key_code == KEY_RIGHT)
	{
		info->dir_x = info->dir_x * cos(info->rot_speed) - \
						info->dir_y * sin(info->rot_speed);
		info->dir_y = old_dir_x * sin(info->rot_speed) + \
						info->dir_y * cos(info->rot_speed);
		info->plane_x = info->plane_x * cos(info->rot_speed) - \
						info->plane_y * sin(info->rot_speed);
		info->plane_y = old_plane_x * sin(info->rot_speed) + \
						info->plane_y * cos(info->rot_speed);
	}
}
