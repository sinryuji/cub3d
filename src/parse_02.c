/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 21:48:44 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/13 11:00:25 by hyeongki         ###   ########.fr       */
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
		*target = 5;
	else if (c == 'W')
		*target = 6;
	else if (c == 'S')
		*target = 7;
	else if (c == 'N')
		*target = 8;
}

int parse_map(t_info *info)
{
	int	i;
	int	j;

	info->map.map = (int **)malloc(sizeof(int *) * info->map.height);
	i = 0;
	while (i < info->map.height)
	{
		info->map.map[i] = (int *)malloc(sizeof(int) * info->map.width);
		j = 0;
		while (j < info->map.width)
			info->map.map[i][j++] = 9;
		j = 0;
		while (j < (int)ft_strlen(info->map.map_data->data))
			convert_data(info, i, j++);
		info->map.map_data = info->map.map_data->next;
		i++;
	}
	
	return (SUCCESS);	
}
