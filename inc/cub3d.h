/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:02:43 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/13 16:41:44 by hyeongki         ###   ########.fr       */
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
	DOOR_CLOSE,
	E = 5,
	W,
	S,
	N,
	OUT_OF_RANGE
};

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
bool	is_map(t_info *info, char *str);
void	free_data(t_map_data **map_data);

/* parse_01.c */
int		parse(t_info *info, char *file_path);

/* parse_02.c */
int		rgb_validation(char *rgb);
int		parse_map(t_info *info);

/* parse_03.c */
int		push_map_data(t_info *info, char *data);
int		set_player(t_info *info, int i, int j, bool *found);
int		validate_fill(t_info *info);

/* parse_04.c */
int		push_wall_path(char **target, char *path);
int		push_floor_color(int *target, int color);

/* set_dir.c */
void	set_dir(t_info *info, int dir);

/* validation_surround_map.c */
void	delete_map_visit(t_info *info);
void	init_map_visit(t_info *info);
int		check_surround(t_info *info, int x, int y);
int		is_map_surround(t_info *info);

#endif
