/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:23:33 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/11 18:37:24 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include <sys/fcntl.h>

int	g_world_map[MAP_WIDTH][MAP_HEIGHT] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

static void	info_init(t_info *info)
{
	int	i;

	info->mlx = mlx_init();
	info->pos_x = 3.0;
	info->pos_y = 3.0;
	info->dir_x = 0.0;
	info->dir_y = 1.0;
	info->plane_x = -0.66;
	info->plane_y = 0.0;
	info->move_speed = 0.25;
	info->rot_speed = 0.1;
	info->mouse_speed = 0.03;
	info->old_x = 0;
	info->buf = (int **)malloc(sizeof(int *) * HEIGHT);
	i = 0;
	while (i < HEIGHT)
		info->buf[i++] = (int *)ft_calloc(WIDTH, sizeof(int));
	init_texture(info);
	init_hud(info);
//	ft_memset(&info->raycast, 0, sizeof(t_raycast));
//	ft_memset(&info->draw, 0, sizeof(t_draw));
}

static void	draw(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			info->img.data[y * WIDTH + x] = info->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

static int	main_loop(t_info *info)
{
	calc(info);
	draw(info);
	draw_minimap(info);
	draw_hud(info);
	return (EXIT_SUCCESS);
}

bool	check_extension(char *file_path)
{
	char	**split;
	bool	ret;

	ret = true;
	split = ft_split(file_path, '.');
	ret = check_split_len(split, 2);
	if (ret && ft_strcmp(split[1], "cub") != 0)
		ret = false;
	ft_split_free(split);
	return (ret);
}

int	parse_wall(t_info *info, char **split)
{
	int		fd;

	if (check_split_len(split, 2) == false)
		return (ERR_WALL_INFO_LEN);
	fd = open(split[1], O_RDONLY);
	if (fd == -1)
		return (ERR_TEX_FILE_OPEN);
	close(fd);
	if (ft_strcmp(split[0], NORTH) == 0)
		info->map.north_path = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], SOUTH) == 0)
		info->map.south_path = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], WEST) == 0)
		info->map.west_path = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], EAST) == 0)
		info->map.east_path = ft_strdup(split[1]);
	return (SUCCESS);
}

int parse_floor(t_info *info, char **split)
{
	if (check_split_len(split, 2) == false)
		return (ERR_FLOOR_INFO_LEN);
	if (ft_strcmp(split[0], FLOOR) == 0)
		info->map.floor_color = rgb_to_int(split[1]);
	else if (ft_strcmp(split[0], CEILLING) == 0)
		info->map.ceilling_color = rgb_to_int(split[1]);
	return (SUCCESS);
}

int	parse_handling(t_info *info, char **split)
{
	if (is_wall(split[0]) == true)	
		return (parse_wall(info, split));
	if (is_floor(split[0]) == true)
		return (parse_floor(info, split));
	return (SUCCESS);
}

int	parse_loop(t_info *info, int fd)
{
	char	*line;
	char	**split;
	int		ret;

	ret = SUCCESS;
	while (ret == SUCCESS)
	{
		line = remove_n(get_next_line(fd));
		if (line == NULL)
			break ;
		split = ft_split(line, ' ');
		ret = parse_handling(info, split);
		free(line);
		ft_split_free(split);
	}
	return (ret);
}

int	parse_map(t_info *info, char *file_path)
{
	int		fd;

	if (check_extension(file_path) == false)
		return (ERR_NOT_CUB);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (ERR_CUB_FILE_OPEN);
	return (parse_loop(info, fd));
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		put_err_exit(ERR_ARGC);
	info_init(&info);
	put_err_exit(parse_map(&info, argv[1]));
	printf("%s\n", info.map.north_path);
	printf("%s\n", info.map.south_path);
	printf("%s\n", info.map.west_path);
	printf("%s\n", info.map.east_path);
	printf("%d\n", info.map.floor_color);
	printf("%d\n", info.map.ceilling_color);
	load_texture(&info);
	info.win = mlx_new_window(info.mlx, WIDTH, HEIGHT, "cub3d");
	info.img.img = mlx_new_image(info.mlx, WIDTH, HEIGHT);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, \
			&info.img.bpp, &info.img.size_line, &info.img.endian);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X11_KEY_PRESS, 0, key_hook, &info);
	mlx_hook(info.win, X11_WIN_DESTROY, 0, exit_hook, &info);
	mlx_hook(info.win, X11_MOUSE_MOVE, 0, mouse_move_hook, &info);
	mlx_hook(info.win, X11_MOUSE_CLICK, 0, mouse_click_hook, &info);
	mlx_loop(info.mlx);
	return (EXIT_SUCCESS);
}
