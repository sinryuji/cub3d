/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:14:13 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/13 13:44:15 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

bool	check_split_len(char **split, int n)
{
	int	i;

	if (split == NULL)
		return (false);
	i = 0;
	while (split[i])
		i++;
	if (i != n)
		return (false);
	return (true);
}

int	rgb_to_int(char *str)
{
	int		red;
	int		green;
	int		blue;
	char	**split;

	split = ft_split(str, ',');
	red = ft_atoi(split[0]) * pow(16, 4);
	green = ft_atoi(split[1]) * pow(16, 2);
	blue = ft_atoi(split[2]);
	ft_split_free(split);
	return (red + green + blue);
}

bool	is_wall(char *str)
{
	if (ft_strcmp(str, NORTH) == 0)
		return (true);
	else if (ft_strcmp(str, SOUTH) == 0)
		return (true);
	else if (ft_strcmp(str, WEST) == 0)
		return (true);
	else if (ft_strcmp(str, EAST) == 0)
		return (true);
	return (false);
}

bool	is_floor(char *str)
{
	if (ft_strcmp(str, FLOOR) == 0)
		return (true);
	else if (ft_strcmp(str, CEILLING) == 0)
		return (true);
	return (false);
}

char	*remove_n(char *str)
{
	char	*new;
	char	*n;

	if (str == NULL)
		return (NULL);
	n = ft_strchr(str, '\n');
	if (n == NULL)
		return (str);
	if (n == str)
		return (str);
	new = ft_strndup(str, n - str);
	free(str);
	return (new);
}
