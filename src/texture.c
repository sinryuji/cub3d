/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:23:45 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/14 12:45:23 by kanghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static bool	is_file_openable(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

bool	validate_texture(void)
{
	if (is_file_openable(TEX_DOOR_PATH)
		&& is_file_openable(TEX_PISTOL_PATH)
		&& is_file_openable(TEX_PISTOL_SHOOT_PATH)
		&& is_file_openable(TEX_CROSSHAIR_PATH)
		&& is_file_openable(TEX_TARGET_PATH))
		return (true);
	return (false);
}

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

	load_xpm(info, info->texture.wall[T_NORTH], info->map.north_path, &img);
	load_xpm(info, info->texture.wall[T_SOUTH], info->map.south_path, &img);
	load_xpm(info, info->texture.wall[T_WEST], info->map.west_path, &img);
	load_xpm(info, info->texture.wall[T_EAST], info->map.east_path, &img);
	load_xpm(info, info->texture.wall[T_OPEN], TEX_DOOR_PATH, &img);
	load_xpm(info, info->texture.wall[T_CLOSE], TEX_DOOR_PATH, &img);
	load_xpm(info, info->texture.wall[T_TARGET], TEX_TARGET_PATH, &img);
	load_xpm(info, info->texture.pistol[P_STAND], TEX_PISTOL_PATH, &img);
	load_xpm(info, info->texture.pistol[P_SHOOT], \
			TEX_PISTOL_SHOOT_PATH, &img);
	load_xpm(info, info->texture.crosshair, TEX_CROSSHAIR_PATH, &img);
}

void	init_texture(t_info *info)
{
	int	i;

	info->texture.wall = (int **)malloc(sizeof(int *) * TEX_WALL_COUNT);
	info->texture.pistol = (int **)malloc(sizeof(int *) * TEX_PISTOL_COUNT);
	info->texture.crosshair = (int *)ft_calloc((CH_TEX_WIDTH * \
				CH_TEX_HEIGHT), sizeof(int));
	i = 0;
	while (i < TEX_WALL_COUNT)
	{
		info->texture.wall[i] = (int *)ft_calloc((WALL_TEX_WIDTH * \
					WALL_TEX_HEIGHT), sizeof(int));
		i++;
	}
	i = 0;
	while (i < TEX_PISTOL_COUNT)
	{
		info->texture.pistol[i] = (int *)ft_calloc((PIS_TEX_WIDTH * \
					PIS_TEX_HEIGHT), sizeof(int));
		i++;
	}
}
