/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:03:09 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/13 12:12:51 by kanghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdbool.h>

# define NORTH ("NO")
# define SOUTH ("SO")
# define WEST ("WE")
# define EAST ("EA")
# define FLOOR ("F")
# define CEILLING ("C")

typedef struct s_map_data
{
	char				*data;
	struct s_map_data	*next;
}	t_map_data;

typedef struct s_map
{
	int					**map;
	int					**visit;
	char				*north_path;
	char				*south_path;
	char				*west_path;
	char				*east_path;
	int					floor_color;
	int					ceilling_color;
	int					width;
	int					height;
	int					dir;
	bool				map_flag;
	bool				map_done;
	struct s_map_data	*map_data;
}	t_map;

#endif
