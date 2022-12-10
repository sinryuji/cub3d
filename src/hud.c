/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:14:16 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/10 23:30:45 by kanghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	init_hud(t_info *info, t_img *pistol, t_img *crosshair)
{
	pistol->img = mlx_new_image(info->mlx, PIS_WIDTH, PIS_HEIGHT);
	pistol->data = (int *)mlx_get_data_addr(pistol->img, &pistol->bpp, \
			&pistol->size_line, &pistol->endian);
	crosshair->img = mlx_new_image(info->mlx, CH_WIDTH, CH_HEIGHT);
	crosshair->data = (int *)mlx_get_data_addr(crosshair->img, &crosshair->bpp, \
			&crosshair->size_line, &crosshair->endian);
}

static void	put_pistol(t_info *info, t_img *pistol)
{
	int	x;
	int	y;

	y = 0;
	while (y < PIS_HEIGHT)
	{
		x = 0;
		while (x < PIS_WIDTH)
		{
			pistol->data[y * PIS_WIDTH + x] = \
							info->texture[PISTOL][y / 9 * PIS_WIDTH + x / 3];
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(info->mlx, info->win, pistol->img, \
			WIDTH / 2 - PIS_WIDTH / 2, HEIGHT - PIS_HEIGHT);
}

static void	put_crosshair(t_info *info, t_img *crosshair)
{
	int	x;
	int	y;

	y = 0;
	while (y < CH_HEIGHT)
	{
		x = 0;
		while (x < CH_WIDTH)
		{
			crosshair->data[y * CH_WIDTH + x] = \
									info->texture[CROSSHAIR][y * CH_WIDTH + x];
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(info->mlx, info->win, \
		crosshair->img, WIDTH / 2 - CH_WIDTH / 2, HEIGHT / 2 - CH_HEIGHT / 2);
}

void	draw_hud(t_info *info)
{
	t_img	pistol;
	t_img	crosshair;

	init_hud(info, &pistol, &crosshair);
	put_pistol(info, &pistol);
	put_crosshair(info, &crosshair);
}
