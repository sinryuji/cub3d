/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:56:35 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/11 21:59:27 by hyeongki         ###   ########.fr       */
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
