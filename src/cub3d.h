/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:02:43 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/09 17:48:23 by kanghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/include/libft.h"
# include "../lib/mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define MAP_WIDTH (24)
# define MAP_HEIGHT (24)
# define WIDTH (960)
# define HEIGHT (720)
# define TEX_WIDTH (64)
# define TEX_HEIGHT (64)
# define TEXTURE_COUNT (4)
# define CEILING_COLOR (0xa39586)
# define FLOOR_COLOR (0x413e3d)

enum e_texture {
	NORTH = 0,
	SOUTH,
	WEST,
	EAST
};

enum e_map
{
	EMPTY,
	WALL
};

# define X11_KEY_PRESS (02)
# define X11_MOUSE_MOVE (06)
# define X11_WIN_DESTROY (17)

# define KEY_ESC (53)
# define KEY_A (0)
# define KEY_S (1)
# define KEY_D (2)
# define KEY_W (13)
# define KEY_LEFT (123)
# define KEY_RIGHT (124)

extern int	g_world_map[MAP_WIDTH][MAP_HEIGHT];

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_line;
	int		bpp;
	int		img_width;
	int		img_height;
	int		endian;
}	t_img;

typedef struct s_raycast
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}	t_raycast;

typedef struct s_draw
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
	int		color;
}	t_draw;

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
}	t_info;

/* raycast_01.c */
void	calc(t_info *info);

/* raycast_02.c */
void	calc_texture(t_info *info, int x);

/* key_hook.c */
int		key_hook(int key_code, t_info *info);
int		exit_hook(t_info *info);

/* mouse_hook.c */
int		mouse_move(int x, int y, t_info *info);

#endif
