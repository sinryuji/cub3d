/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:45:25 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/12 13:58:51 by kanghyki         ###   ########.fr       */
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

static void	calc_vector(t_info *info)
{
	info->raycast.camera_x = 0;
	info->raycast.ray_dir_x = info->dir_x + info->plane_x * \
								info->raycast.camera_x;
	info->raycast.ray_dir_y = info->dir_y + info->plane_y * \
								info->raycast.camera_x;
	info->raycast.map_x = (int)info->pos_x;
	info->raycast.map_y = (int)info->pos_y;
	info->raycast.delta_dist_x = fabs(1 / info->raycast.ray_dir_x);
	info->raycast.delta_dist_y = fabs(1 / info->raycast.ray_dir_y);
}

static void hit_what(t_info *info)
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
		{
			info->raycast.hit = true;
			info->raycast.hit_stuff = g_world_map[info->raycast.map_y][info->raycast.map_x];
		}
	}
}

static int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}


static void	interact_door(t_info *info)
{
	int	what = 0;
	calc_vector(info);
	calc_step(info);
	hit_what(info);
	what = info->raycast.hit_stuff;
	if (what == DOOR_CLOSE
			|| what == DOOR_OPEN)
	{
		if (ft_abs(info->pos_x - info->raycast.map_x) < 2 && ft_abs(info->pos_y - info->raycast.map_y) < 2)
		{
			if (what == DOOR_CLOSE)
				g_world_map[info->raycast.map_y][info->raycast.map_x] = DOOR_OPEN;
			else if (what == DOOR_OPEN)
				g_world_map[info->raycast.map_y][info->raycast.map_x] = DOOR_CLOSE;
		}
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
	else if (key_code == KEY_F)
		interact_door(info);
	if (info->pos_x < 1.3)
		info->pos_x = 1.3;
	if (info->pos_y < 1.3)
		info->pos_y = 1.3;
	return (EXIT_SUCCESS);
}
