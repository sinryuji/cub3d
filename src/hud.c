/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:14:16 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/11 00:18:10 by kanghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_hud(t_info *info)
{
	info->hud.pistol.width = PIS_TEX_WIDTH * PIS_TEX_MEG;
	info->hud.pistol.height = PIS_TEX_HEIGHT * PIS_TEX_MEG;
	info->hud.pistol.img.img = mlx_new_image( \
			info->mlx, info->hud.pistol.width, info->hud.pistol.height);
	info->hud.pistol.img.data = (int *)mlx_get_data_addr( \
			info->hud.pistol.img.img, \
			&info->hud.pistol.img.bpp, \
			&info->hud.pistol.img.size_line, \
			&info->hud.pistol.img.endian);
	info->hud.crosshair.img.img = mlx_new_image( \
			info->mlx, CH_TEX_WIDTH, CH_TEX_HEIGHT);
	info->hud.crosshair.img.data = (int *)mlx_get_data_addr( \
			info->hud.crosshair.img.img, \
			&info->hud.crosshair.img.bpp, \
			&info->hud.crosshair.img.size_line, \
			&info->hud.crosshair.img.endian);
}

static void	put_pistol(t_info *info, t_img *pistol)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->hud.pistol.height)
	{
		x = 0;
		while (x < info->hud.pistol.width)
		{
			pistol->data[y * info->hud.pistol.width + x] = \
					info->texture[PISTOL][y / (PIS_TEX_MEG * PIS_TEX_MEG) * \
					info->hud.pistol.width + x / PIS_TEX_MEG];
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(info->mlx, info->win, pistol->img, \
			WIDTH / 2 - info->hud.pistol.width / 2, HEIGHT - info->hud.pistol.height);
}

static void	put_crosshair(t_info *info, t_img *crosshair)
{
	int	x;
	int	y;

	y = 0;
	while (y < CH_TEX_HEIGHT)
	{
		x = 0;
		while (x < CH_TEX_WIDTH)
		{
			crosshair->data[y * CH_TEX_WIDTH + x] = \
							info->texture[CROSSHAIR][y * CH_TEX_WIDTH + x];
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(info->mlx, info->win, \
		crosshair->img, WIDTH / 2 - CH_TEX_WIDTH / \
		2, HEIGHT / 2 - CH_TEX_HEIGHT / 2);
}

void	draw_hud(t_info *info)
{
	put_pistol(info, &info->hud.pistol.img);
	put_crosshair(info, &info->hud.crosshair.img);
}
