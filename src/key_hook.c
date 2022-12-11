/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:45:25 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/11 10:48:56 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	exit_hook(t_info *info)
{
	mlx_destroy_window(info->mlx, info->win);
	exit(EXIT_SUCCESS);
}

static void	key_move_ws(int key_code, t_info *info)
{
	if (key_code == KEY_W)
	{
		if (g_world_map[(int)(info->pos_y + info->dir_y * \
					info->move_speed)][(int)(info->pos_x)] == EMPTY)
			info->pos_y += info->dir_y * info->move_speed;
		if (g_world_map[(int)(info->pos_y)][(int)(info->pos_x + \
					info->dir_x * info->move_speed)] == EMPTY)
			info->pos_x += info->dir_x * info->move_speed;
	}
	else if (key_code == KEY_S)
	{
		if (g_world_map[(int)(info->pos_y - info->dir_y * \
					info->move_speed)][(int)(info->pos_x)] == EMPTY)
			info->pos_y -= info->dir_y * info->move_speed;
		if (g_world_map[(int)(info->pos_y)][(int)(info->pos_x - \
					info->dir_x * info->move_speed)] == EMPTY)
			info->pos_x -= info->dir_x * info->move_speed;
	}
}

static void	key_move_ad(int key_code, t_info *info)
{
	if (key_code == KEY_D)
	{
		if (g_world_map[(int)(info->pos_y + info->dir_x * \
					info->move_speed)][(int)(info->pos_x)] == EMPTY)
			info->pos_y += info->dir_x * info->move_speed;
		if (g_world_map[(int)(info->pos_y)][(int)(info->pos_x - \
					info->dir_y * info->move_speed)] == EMPTY)
			info->pos_x -= info->dir_y * info->move_speed;
	}
	else if (key_code == KEY_A)
	{
		if (g_world_map[(int)(info->pos_y - info->dir_x * \
					info->move_speed)][(int)(info->pos_x)] == EMPTY)
			info->pos_y -= info->dir_x * info->move_speed;
		if (g_world_map[(int)(info->pos_y)][(int)(info->pos_x + \
					info->dir_y * info->move_speed)] == EMPTY)
			info->pos_x += info->dir_y * info->move_speed;
	}
}

static void	key_rotate(int key_code, t_info *info, \
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

int	key_hook(int key_code, t_info *info)
{
	if (key_code == KEY_ESC)
		exit_hook(info);
	else if (key_code == KEY_W || key_code == KEY_S)
		key_move_ws(key_code, info);
	else if (key_code == KEY_A || key_code == KEY_D)
		key_move_ad(key_code, info);
	else if (key_code == KEY_LEFT || key_code == KEY_RIGHT)
		key_rotate(key_code, info, info->dir_x, info->plane_x);
	if (info->pos_x < 1.3)
		info->pos_x = 1.3;
	if (info->pos_y < 1.3)
		info->pos_y = 1.3;
	return (EXIT_SUCCESS);
}
