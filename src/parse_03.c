/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 23:54:01 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/13 16:25:56 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static t_map_data	*new_map_data(char *data)
{
	t_map_data	*new;

	if (data == NULL)
		return (NULL);
	new = (t_map_data *)malloc(sizeof(t_map_data));
	new->next = NULL;
	new->data = ft_strdup(data);
	return (new);
}

static	t_map_data	*get_last_node(t_map_data *map_data)
{
	while (map_data->next)
		map_data = map_data->next;
	return (map_data);
}

int	push_map_data(t_info *info, char *data)
{
	t_map_data	*new;
	int			width_tmp;

	new = new_map_data(data);
	width_tmp = ft_strlen(new->data);
	if (width_tmp >= info->map.width)
		info->map.width = width_tmp;
	if (info->map.map_data == NULL)
		info->map.map_data = new;
	else
		get_last_node(info->map.map_data)->next = new;
	info->map.height++;
	return (SUCCESS);
}

int	set_player(t_info *info, int i, int j, bool *found)
{
	int	*player;

	player = &info->map.map[i][j];
	if (*player >= E && *player <= N)
	{
		if (*found == true)
			return (ERR_DUP_PLAYER);
		info->pos_x = j;
		info->pos_x = j;
		info->pos_y = i;
		set_dir(info, *player);
		*player = 0;
		*found = true;
	}
	return (SUCCESS);
}

int	validate_fill(t_info *info)
{
	if (info->map.north_path == NULL)
		return (ERR_EMPTY_INFO);
	if (info->map.south_path == NULL)
		return (ERR_EMPTY_INFO);
	if (info->map.west_path == NULL)
		return (ERR_EMPTY_INFO);
	if (info->map.east_path == NULL)
		return (ERR_EMPTY_INFO);
	if (info->map.floor_color == -1)
		return (ERR_EMPTY_INFO);
	if (info->map.ceilling_color == -1)
		return (ERR_EMPTY_INFO);
	if (info->map.map_flag == false)
		return (ERR_EMPTY_INFO);
	return (SUCCESS);
}
