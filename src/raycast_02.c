/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:44:07 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/11 15:59:53 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	get_texture_color(t_info *info, int index);

void	calc_texture(t_info *info, int x)
{
	int	y;
	int	index;

	y = 0;
	while (y < HEIGHT)
	{
		if (y >= info->draw.draw_start && y < info->draw.draw_end)
		{
			info->draw.tex_y = (int)info->draw.tex_pos & (WALL_TEX_HEIGHT - 1);
			info->draw.tex_pos += info->draw.step;
			index = info->draw.tex_y * WALL_TEX_WIDTH + info->draw.tex_x;
			info->buf[y][x] = get_texture_color(info, index);
		}	
		else if (y < info->draw.draw_start)
			info->buf[y][x] = CEILING_COLOR;
		else
			info->buf[y][x] = FLOOR_COLOR;
		++y;
	}
}

int	get_texture_color(t_info *info, int index)
{
	int	ret;

	ret = 0;
	if (info->raycast.side == 1 && info->raycast.step_y == 1)
		ret = info->texture[T_NORTH][index];
	else if (info->raycast.side == 1 && info->raycast.step_y == -1)
		ret = info->texture[T_SOUTH][index];
	else if (info->raycast.side == 0 && info->raycast.step_x == 1)
		ret = info->texture[T_EAST][index];
	else if (info->raycast.side == 0 && info->raycast.step_x == -1)
		ret = info->texture[T_WEST][index];
	return (ret);
}
