/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanghyki <kanghyki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 21:04:13 by kanghyki          #+#    #+#             */
/*   Updated: 2022/12/12 21:16:37 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

# include "draw.h"
# include "hud.h"
# include "img.h"
# include "minimap.h"
# include "map.h"
# include "raycast.h"
# include "texture.h"

typedef struct s_info
{
	void				*mlx;
	void				*win;
	struct s_img		img;
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	double				move_speed;
	double				rot_speed;
	double				mouse_speed;
	int					**buf;
	double				old_x;
	struct s_raycast	raycast;
	struct s_draw		draw;
	struct s_minimap	minimap;
	struct s_hud		hud;
	struct s_map		map;
	struct s_texture	texture;
}	t_info;

#endif
