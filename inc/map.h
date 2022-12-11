/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:03:09 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/11 17:04:24 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

# define NORTH ("NO")
# define SOUTH ("SO")
# define WEST ("WE")
# define EAST ("EA")
# define FLOOR ("F")
# define CEILLING ("C")

typedef struct s_map
{
	int		**map;
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
	int		floor_color;
	int		ceilling_color;
	int		width;
	int		height;
	int		pos_x;
	int		pos_y;
	int		dir;
}	t_map;

#endif
