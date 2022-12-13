/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanghyki <kanghyki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 08:33:05 by kanghyki          #+#    #+#             */
/*   Updated: 2022/12/13 14:23:44 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

/* define wall */
# define TEX_WALL_COUNT (6)
# define WALL_TEX_WIDTH (64)
# define WALL_TEX_HEIGHT (64)

/* define pistol */
# define TEX_PISTOL_COUNT (2)
# define PIS_TEX_WIDTH (192)
# define PIS_TEX_HEIGHT (192)
# define PIS_TEX_MEG (3)

/* define crosshair */
# define CH_TEX_WIDTH (32)
# define CH_TEX_HEIGHT (32)

/* define texture path */
# define TEX_DOOR_PATH "textures/door.xpm"
# define TEX_PISTOL_PATH "textures/pistol.xpm"
# define TEX_PISTOL_SHOOT_PATH "textures/pistol_shoot.xpm"
# define TEX_CROSSHAIR_PATH "textures/crosshair.xpm"

enum e_wall
{
	T_NORTH = 0,
	T_SOUTH,
	T_WEST,
	T_EAST,
	T_OPEN,
	T_CLOSE
};

enum e_pistol
{
	P_STAND = 0,
	P_SHOOT
};

typedef struct s_texture
{
	int	**wall;
	int	**pistol;
	int	*crosshair;
}	t_texture;

#endif
