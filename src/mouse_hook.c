/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:54:55 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/10 23:56:31 by kanghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	move_left(t_info *info, double old_dir_x, double old_plane_x)
{
	info->dir_x = info->dir_x * cos(-info->mouse_speed) - \
					info->dir_y * sin(-info->mouse_speed);
	info->dir_y = old_dir_x * sin(-info->mouse_speed) + \
					info->dir_y * cos(-info->mouse_speed);
	info->plane_x = info->plane_x * cos(-info->mouse_speed) - \
					info->plane_y * sin(-info->mouse_speed);
	info->plane_y = old_plane_x * sin(-info->mouse_speed) + \
					info->plane_y * cos(-info->mouse_speed);
}

static void	move_right(t_info *info, double old_dir_x, double old_plane_x)
{
	info->dir_x = info->dir_x * cos(info->mouse_speed) - \
					info->dir_y * sin(info->mouse_speed);
	info->dir_y = old_dir_x * sin(info->mouse_speed) + \
					info->dir_y * cos(info->mouse_speed);
	info->plane_x = info->plane_x * cos(info->mouse_speed) - \
					info->plane_y * sin(info->mouse_speed);
	info->plane_y = old_plane_x * sin(info->mouse_speed) + \
					info->plane_y * cos(info->mouse_speed);
}

int	mouse_move_hook(int x, int y, t_info *info)
{
	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return (EXIT_FAILURE);
	if (x < info->old_x)
		move_left(info, info->dir_x, info->plane_x);
	else if (x > info->old_x)
		move_right(info, info->dir_x, info->plane_x);
	info->old_x = x;
	return (EXIT_SUCCESS);
}
