/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:02:43 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/12 17:02:52 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "error.h"
# include "info.h"
# include "key.h"
# include "texture.h"
# include "../lib/libft/include/libft.h"
# include "../lib/mlx/mlx.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

/* define map */
# define MAP_WIDTH (24)
# define MAP_HEIGHT (24)

/* define resolution */
# define WIDTH (960)
# define HEIGHT (720)

/* define ceiling and floor color */
# define CEILING_COLOR (0xa39586)
# define FLOOR_COLOR (0x413e3d)

enum e_map
{
	EMPTY,
	WALL,
	DOOR_OPEN,
	DOOR_CLOSE
};

extern int	g_world_map[MAP_WIDTH][MAP_HEIGHT];

/* raycast_01.c */
void	calc(t_info *info);
void	calc_step(t_info *info);
void	calc_vector(t_info *info, int x);
void	calc_ray_until_hit(t_info *info, bool(*condition)(int));

/* raycast_02.c */
void	calc_perp_wall_dist(t_info *info);
void	calc_draw_info(t_info *info);
void	calc_texture(t_info *info, int x);

/* key_hook.c */
int		key_hook(int key_code, t_info *info);
int		exit_hook(t_info *info);

/* key_move.c */
void	key_move_ws(int key_code, t_info *info);
void	key_move_ad(int key_code, t_info *info);

/* key_rotate */
void	key_rotate(int key_code, t_info *info, \
		double old_dir_x, double old_plane_x);

/* door.c */
void	interact_door(t_info *info);

/* mouse_hook.c */
int		mouse_move_hook(int x, int y, t_info *info);
int		mouse_click_hook(int button, int x, int y, t_info *info);

/* minimap.c */
void	init_minimap(t_info *info);
void	draw_minimap(t_info *info);

/* hud.c */
void	init_hud(t_info *info);
void	draw_hud(t_info *info);
void	draw_pistol(t_info *info, t_img *pistol, int status);

/* texture.c */
void	load_texture(t_info *info);
void	init_texture(t_info *info);

/* error.c */
void	put_err_exit(int err);

/* util_01.c */
bool	check_split_len(char **split, int n);
int		rgb_to_int(char *str);
bool	is_wall(char *str);
bool	is_floor(char *str);
char	*remove_n(char *str);

/* util_02.c */
bool	check_extension(char *file_path);
bool	check_contain_char(char *str);
bool	is_map(char *str);

/* parse_01.c */
int		parse(t_info *info, char *file_path);

/* parse_02.c */
int		rgb_validation(char *rgb);
int		parse_map(t_info *info, char **split, int fd);

#endif
