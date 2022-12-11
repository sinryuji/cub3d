/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:23:45 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/11 16:00:10 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	load_xpm(t_info *info, int *texture, char *path, t_img *img)
{
	int	x;
	int	y;

	img->img = mlx_xpm_file_to_image(info->mlx, path, \
			&img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, \
			&img->size_line, &img->endian);
	y = 0;
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = \
				img->data[img->img_width * y + x];
			++x;
		}
		++y;
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	load_texture(t_info *info)
{
	t_img	img;

	load_xpm(info, info->texture[T_NORTH], "textures/north.xpm", &img);
	load_xpm(info, info->texture[T_SOUTH], "textures/south.xpm", &img);
	load_xpm(info, info->texture[T_WEST], "textures/east.xpm", &img);
	load_xpm(info, info->texture[T_EAST], "textures/west.xpm", &img);
	load_xpm(info, info->texture[PISTOL], "textures/pistol.xpm", &img);
	load_xpm(info, info->texture[PISTOL_SHOOT], \
			"textures/pistol_shoot.xpm", &img);
	load_xpm(info, info->texture[CROSSHAIR], "textures/crosshair.xpm", &img);
}

void	init_texture(t_info *info)
{
	int	i;

	info->texture = (int **)malloc(sizeof(int *) * TEX_COUNT);
	i = 0;
	while (i < TEX_COUNT)
	{
		if (i < 4)
			info->texture[i] = (int *)ft_calloc((WALL_TEX_WIDTH * \
						WALL_TEX_HEIGHT), sizeof(int));
		else if (i < 6)
			info->texture[i] = (int *)ft_calloc((PIS_TEX_WIDTH * \
						PIS_TEX_HEIGHT), sizeof(int));
		else
			info->texture[i] = (int *)ft_calloc((CH_TEX_WIDTH * \
						CH_TEX_HEIGHT), sizeof(int));
		i++;
	}
}
