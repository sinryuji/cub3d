/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:23:33 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/13 21:12:10 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include <sys/fcntl.h>

static void	info_init(t_info *info)
{
	int	i;

	info->mlx = mlx_init();
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

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		put_err_exit(ERR_ARGC);
	if (validate_texture() == false)
		put_err_exit(ERR_TEX_FILE_OPEN);
	info_init(&info);
	put_err_exit(parse(&info, argv[1]));
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
