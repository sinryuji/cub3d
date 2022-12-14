/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanghyki <kanghyki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:50:25 by kanghyki          #+#    #+#             */
/*   Updated: 2022/12/14 13:40:15 by kanghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "img.h"

# define MM_RADIUS (100)
# define MM_BG_COLOR (0x66000000)
# define MM_WALL_COLOR (0x66665b53)

# define MM_DOOR_CLOSE_COLOR (0x66689c69)
# define MM_DOOR_OPEN_COLOR (0x66355436)

# define MM_PLAYER_COLOR (0x66e5c07b)
# define MM_EMPTY (0xFF000000)

# define MM_TARGET_COLOR (0x66d73925)

typedef struct s_minimap
{
	double			ratio;
	struct s_img	img;
}	t_minimap;

#endif
