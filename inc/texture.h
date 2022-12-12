/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanghyki <kanghyki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 08:33:05 by kanghyki          #+#    #+#             */
/*   Updated: 2022/12/12 09:15:54 by kanghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

/* define wall */
# define TEX_WALL_COUNT (4)
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

/* define door */
# define TEX_DOOR_COUNT (2)
# define DOOR_TEX_WIDTH (64)
# define DOOR_TEX_HEIGHT (64)


enum e_wall
{
	T_NORTH = 0,
	T_SOUTH,
	T_WEST,
	T_EAST,
};

enum e_pistol
{
	P_STAND = 0,
	P_SHOOT
};

enum e_door
{
	D_OPEN = 0,
	D_CLOSE
};

typedef struct s_texture
{
	int	**wall;
	int	**pistol;
	int	**door;
	int	*crosshair;
}	t_texture;

#endif
