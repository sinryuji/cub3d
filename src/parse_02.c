/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 21:48:44 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/12 21:48:32 by hyeongki         ###   ########.fr       */
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

int parse_map(t_info *info, char *line)
{
	(void)info;
	(void)line;	
	return (SUCCESS);	
}
