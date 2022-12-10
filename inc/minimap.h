/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanghyki <kanghyki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:50:25 by kanghyki          #+#    #+#             */
/*   Updated: 2022/12/10 21:51:46 by kanghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "img.h"

# define MINIMAP_WIDTH (120)
# define MINIMAP_HEIGHT (90)
# define MINIMAP_BG_COLOR (0)
# define MINIMAP_WALL_COLOR (0x665b53)
# define MINIMAP_PLAYER_COLOR (0xe5c07b)

typedef struct s_minimap
{
//	int				range;
	double			x_ratio;
	double			y_ratio;
	struct s_img	img;
}	t_minimap;

#endif
