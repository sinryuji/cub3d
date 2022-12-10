/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:02:43 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/10 23:47:36 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "info.h"
# include "key.h"
# include "../lib/libft/include/libft.h"
# include "../lib/mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

/* define map */
# define MAP_WIDTH (24)
# define MAP_HEIGHT (24)

/* define resolution */
# define WIDTH (960)
# define HEIGHT (720)

/* define texture */
# define TEX_COUNT (7)
# define WALL_TEX_WIDTH (64)
# define WALL_TEX_HEIGHT (64)
# define PIS_TEX_WIDTH (192)
# define PIS_TEX_HEIGHT (192)
# define PIS_TEX_MEG (3)
# define CH_TEX_WIDTH (32)
# define CH_TEX_HEIGHT (32)

/* define ceiling and floor color */
# define CEILING_COLOR (0xa39586)
# define FLOOR_COLOR (0x413e3d)

enum e_texture {
	NORTH = 0,
	SOUTH,
	WEST,
	EAST,
	PISTOL,
	PISTOL_SHOOT,
	CROSSHAIR
};

enum e_map
{
	EMPTY,
	WALL,
	PLAYER
};

extern int	g_world_map[MAP_WIDTH][MAP_HEIGHT];

/* raycast_01.c */
void	calc(t_info *info);

/* raycast_02.c */
void	calc_texture(t_info *info, int x);

/* key_hook.c */
int		key_hook(int key_code, t_info *info);
int		exit_hook(t_info *info);

/* mouse_hook.c */
int		mouse_move_hook(int x, int y, t_info *info);

/* minimap.c */
void	init_minimap(t_info *info);
void	draw_minimap(t_info *info);

/* hud.c */
void	draw_hud(t_info *info);

/* texture.c */
void	load_texture(t_info *info);
void	init_texture(t_info *info);

#endif
