/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:44:07 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/07 22:13:09 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_texture(t_info *info, int x)
{
	int	y;
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		if (y >= info->draw.draw_start && y < info->draw.draw_end)
		{
			info->draw.tex_y = (int)info->draw.tex_pos & (TEX_HEIGHT - 1);
			info->draw.tex_pos += info->draw.step;
			if (info->raycast.side == 1 && info->raycast.step_y == 1)
				color = info->texture[0][TEX_HEIGHT * info->draw.tex_y + info->draw.tex_x];
			else if (info->raycast.side == 1 && info->raycast.step_y == -1)
				color = info->texture[1][TEX_HEIGHT * info->draw.tex_y + info->draw.tex_x];
			else if (info->raycast.side == 0 && info->raycast.step_x == 1)
				color = info->texture[2][TEX_HEIGHT * info->draw.tex_y + info->draw.tex_x];
			else if (info->raycast.side == 0 && info->raycast.step_x == -1)
				color = info->texture[3][TEX_HEIGHT * info->draw.tex_y + info->draw.tex_x];
			else
				color = (color >> 1)&8315711;
			info->buf[y][x] = color;
		}	
		else if(y < info->draw.draw_start)
			info->buf[y][x] = 0xe3c8d7;
		else
			info->buf[y][x] = 0x786f74;
		y++;
	}
}
