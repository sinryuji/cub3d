/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanghyki <kanghyki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:51:36 by kanghyki          #+#    #+#             */
/*   Updated: 2022/12/13 13:05:56 by kanghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static bool	is_passable(int where);

void	key_move_ws(int key_code, t_info *info)
{
	double	y_move;
	double	x_move;

	y_move = info->dir_y * info->move_speed;
	x_move = info->dir_x * info->move_speed;
	if (key_code == KEY_W)
	{
		if (is_passable(\
				info->map.map[(int)(info->pos_y + y_move)][(int)(info->pos_x)]))
			info->pos_y += y_move;
		if (is_passable(\
				info->map.map[(int)(info->pos_y)][(int)(info->pos_x + x_move)]))
			info->pos_x += x_move;
	}
	else if (key_code == KEY_S)
	{
		if (is_passable(\
				info->map.map[(int)(info->pos_y - y_move)][(int)(info->pos_x)]))
			info->pos_y -= y_move;
		if (is_passable(\
				info->map.map[(int)(info->pos_y)][(int)(info->pos_x - x_move)]))
			info->pos_x -= x_move;
	}
}

void	key_move_ad(int key_code, t_info *info)
{
	double	y_move;
	double	x_move;

	y_move = info->dir_y * info->move_speed;
	x_move = info->dir_x * info->move_speed;
	if (key_code == KEY_D)
	{
		if (is_passable(\
				info->map.map[(int)(info->pos_y + x_move)][(int)(info->pos_x)]))
			info->pos_y += x_move;
		if (is_passable(\
				info->map.map[(int)(info->pos_y)][(int)(info->pos_x - y_move)]))
			info->pos_x -= y_move;
	}
	else if (key_code == KEY_A)
	{
		if (is_passable(\
				info->map.map[(int)(info->pos_y - x_move)][(int)(info->pos_x)]))
			info->pos_y -= x_move;
		if (is_passable(\
				info->map.map[(int)(info->pos_y)][(int)(info->pos_x + y_move)]))
			info->pos_x += y_move;
	}
}

static bool	is_passable(int where)
{
	if (where == EMPTY
		|| where == DOOR_OPEN)
		return (true);
	return (false);
}
