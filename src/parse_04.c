/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_04.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:28:26 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/13 16:47:13 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	push_wall_path(char **target, char *path)
{
	if (*target != NULL)
		return (ERR_DUP_INFO);
	*target = ft_strdup(path);
	return (SUCCESS);
}

int	push_floor_color(int *target, int color)
{
	if (*target != -1)
		return (ERR_DUP_INFO);
	*target = color;
	return (SUCCESS);
}
