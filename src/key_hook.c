/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:45:25 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/12 15:54:47 by kanghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	exit_hook(t_info *info)
{
	mlx_destroy_window(info->mlx, info->win);
	exit(EXIT_SUCCESS);
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
