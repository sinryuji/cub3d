/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanghyki <kanghyki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 21:04:13 by kanghyki          #+#    #+#             */
/*   Updated: 2022/12/10 23:18:22 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

# include "draw.h"
# include "minimap.h"
# include "img.h"
# include "raycast.h"

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
	int					**texture;
	struct s_raycast	raycast;
	struct s_draw		draw;
	double				old_x;
	struct s_minimap	minimap;
}	t_info;

#endif
