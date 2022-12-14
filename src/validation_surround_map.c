/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_surround_map.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:51:55 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/14 12:04:53 by kanghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_surround(t_info *info)
{
	int	ret;

	init_map_visit(info);
	ret = is_map_surround(info);
	delete_map_visit(info);
	if (ret != SUCCESS)
		return (ret);
	init_map_visit(info);
	ret = is_pos_surround(info, info->pos_x, info->pos_y);
	delete_map_visit(info);
	if (ret != SUCCESS)
		return (ret);
	return (SUCCESS);
}

void	init_map_visit(t_info *info)
{
	int	i;

	i = 0;
	info->map.visit = (int **)malloc(sizeof(int *) * info->map.height);
	while (i < info->map.height)
	{
		info->map.visit[i] = ft_calloc(info->map.width, sizeof(int));
		++i;
	}
}

void	delete_map_visit(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->map.height)
	{
		free(info->map.visit[i]);
		++i;
	}
	free(info->map.visit);
}

int	is_pos_surround(t_info *info, int x, int y)
{
	if ((x < 0 || x >= info->map.width || y < 0 || y >= info->map.height)
		|| info->map.map[y][x] == OUT_OF_RANGE)
		return (ERR_NOT_CLOSED_MAP);
	if (info->map.visit[y][x] == 1 || info->map.map[y][x] == 1)
		return (SUCCESS);
	info->map.visit[y][x] = 1;
	if (is_pos_surround(info, x + 0, y + 1) != SUCCESS)
		return (ERR_NOT_CLOSED_MAP);
	if (is_pos_surround(info, x + 1, y + 0) != SUCCESS)
		return (ERR_NOT_CLOSED_MAP);
	if (is_pos_surround(info, x + 0, y + -1) != SUCCESS)
		return (ERR_NOT_CLOSED_MAP);
	if (is_pos_surround(info, x + -1, y + 0) != SUCCESS)
		return (ERR_NOT_CLOSED_MAP);
	return (SUCCESS);
}

int	is_map_surround(t_info *info)
{
	int	y;
	int	x;

	y = 0;
	while (y < info->map.height)
	{
		x = 0;
		while (x < info->map.width)
		{
			if (info->map.map[y][x] == 0 && info->map.visit[y][x] == 0)
				if (is_pos_surround(info, x, y) != SUCCESS)
					return (ERR_NOT_CLOSED_MAP);
			++x;
		}
		++y;
	}
	return (SUCCESS);
}
