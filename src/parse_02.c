/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 21:48:44 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/13 13:57:54 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	rgb_validation(char *rgb)
{
	char	**split;
	int		i;
	int		num;

	split = ft_split(rgb, ',');
	if (check_split_len(split, 3) == false)
		return (ERR_RGB_LEN);
	i = 0;
	while (i < 3)
	{
		if (check_contain_char(split[i]) == false)
			return (ERR_RGB_VAL);
		num = ft_atoi(split[i]);
		if (num < 0 || num > 255)
			return (ERR_RGB_RANGE);
		i++;
	}
	return (SUCCESS);
}

static void	convert_data(t_info *info, int i, int j)
{
	char	c;
	int		*target;

	c = info->map.map_data->data[j];
	target = &info->map.map[i][j];
	if (c == '0' || c == '1' || c == '2' || c == '3')
		*target = ft_atoi(&c);
	else if (c == 'E')
		*target = E;
	else if (c == 'W')
		*target = W;
	else if (c == 'S')
		*target = S;
	else if (c == 'N')
		*target = N;
}

int	check_player(t_info *info)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	while (i < info->map.height)
	{
		j = 0;
		while (j < info->map.width)
		{
			player = info->map.map[i][j];
			if (player >= E && player <= N)
			{
				info->pos_x = j;
				info->pos_y = i;
				info->map.map[i][j] = 0;
				set_dir(info, player);
				return (SUCCESS);
			}
			j++;
		}
		i++;
	}
	return (ERR_NO_PLAYER);
}

int	validate_map(t_info *info)
{
	int	ret;

	ret = check_player(info);
	if (ret != SUCCESS)
		return (ret);
	init_map_visit(info);
	ret = is_map_surround(info);
	delete_map_visit(info);
	if (ret != SUCCESS)
		return (ret);
	init_map_visit(info);
	ret = check_surround(info, info->pos_x, info->pos_y);
	delete_map_visit(info);
	if (ret != SUCCESS)
		return (ret);
	return (SUCCESS);
}

int	parse_map(t_info *info)
{
	int			i;
	int			j;
	t_map_data	*tmp;

	info->map.map = (int **)malloc(sizeof(int *) * info->map.height);
	i = 0;
	while (i < info->map.height)
	{
		info->map.map[i] = (int *)malloc(sizeof(int) * info->map.width);
		j = 0;
		while (j < info->map.width)
			info->map.map[i][j++] = OUT_OF_RANGE;
		j = 0;
		while (j < (int)ft_strlen(info->map.map_data->data))
			convert_data(info, i, j++);
		tmp = info->map.map_data;
		info->map.map_data = info->map.map_data->next;
		free_data(&tmp);
		i++;
	}
	return (validate_map(info));
}
