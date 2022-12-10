/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:44:07 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/10 17:43:12 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_texture(t_info *info, int x)
{
	int	y;
	int	color;
	int	index;

	y = 0;
	while (y < HEIGHT)
	{
		if (y >= info->draw.draw_start && y < info->draw.draw_end)
		{
			info->draw.tex_y = (int)info->draw.tex_pos & (WALL_TEX_HEIGHT - 1);
			info->draw.tex_pos += info->draw.step;
			index = info->draw.tex_y * WALL_TEX_WIDTH + info->draw.tex_x;
			if (info->raycast.side == 1 && info->raycast.step_y == 1)
				color = info->texture[NORTH][index];
			else if (info->raycast.side == 1 && info->raycast.step_y == -1)
				color = info->texture[SOUTH][index];
			else if (info->raycast.side == 0 && info->raycast.step_x == 1)
				color = info->texture[EAST][index];
			else if (info->raycast.side == 0 && info->raycast.step_x == -1)
				color = info->texture[WEST][index];
			info->buf[y][x] = color;
		}	
		else if (y < info->draw.draw_start)
			info->buf[y][x] = CEILING_COLOR;
		else
			info->buf[y][x] = FLOOR_COLOR;
		++y;
	}
}
