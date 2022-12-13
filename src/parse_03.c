/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 23:54:01 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/13 09:50:05 by hyeongki         ###   ########.fr       */
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

	if (data == NULL)
		return (ERR_WRONG_MAP);
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
