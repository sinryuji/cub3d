/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:14:16 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/10 23:50:52 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	init_hud(t_info *info, t_img *pistol, t_img *crosshair)
{
	pistol->img = mlx_new_image(info->mlx, info->pis_width, info->pis_height);
	pistol->data = (int *)mlx_get_data_addr(pistol->img, &pistol->bpp, \
			&pistol->size_line, &pistol->endian);
	crosshair->img = mlx_new_image(info->mlx, CH_TEX_WIDTH, CH_TEX_HEIGHT);
	crosshair->data = (int *)mlx_get_data_addr(crosshair->img, &crosshair->bpp, \
			&crosshair->size_line, &crosshair->endian);
}

static void	put_pistol(t_info *info, t_img *pistol)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->pis_height)
	{
		x = 0;
		while (x < info->pis_width)
		{
			pistol->data[y * info->pis_width + x] = \
					info->texture[PISTOL][y / (PIS_TEX_MEG * PIS_TEX_MEG) * \
					info->pis_width + x / PIS_TEX_MEG];
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(info->mlx, info->win, pistol->img, \
			WIDTH / 2 - info->pis_width / 2, HEIGHT - info->pis_height);
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
	t_img	pistol;
	t_img	crosshair;

	info->pis_width = PIS_TEX_WIDTH * PIS_TEX_MEG;
	info->pis_height = PIS_TEX_HEIGHT * PIS_TEX_MEG;
	init_hud(info, &pistol, &crosshair);
	put_pistol(info, &pistol);
	put_crosshair(info, &crosshair);
}
