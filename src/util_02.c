/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:56:35 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/13 09:27:55 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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

bool	check_contain_char(char *str)
{
	int	i;

	if (str == NULL)
		return (false);
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

bool	is_map(t_info *info, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '3') || str[i] == 'N' || str[i] == 'S' \
				|| str[i] == 'E' || str[i] == 'W' || str[i] == ' ')
			i++;
		else
		{
			if (info->map.map_flag == true)
				info->map.map_done = true;
			return (false);
		}
	}
	if (info->map.map_done == true)
		return (false);
	info->map.map_flag = true;
	return (true);
}
