/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:55:09 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/11 23:38:12 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	parse_wall(t_info *info, char **split)
{
	int		fd;

	if (check_split_len(split, 2) == false)
		return (ERR_WALL_INFO_LEN);
	fd = open(split[1], O_RDONLY);
	if (fd == -1)
		return (ERR_TEX_FILE_OPEN);
	close(fd);
	if (ft_strcmp(split[0], NORTH) == 0)
		info->map.north_path = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], SOUTH) == 0)
		info->map.south_path = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], WEST) == 0)
		info->map.west_path = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], EAST) == 0)
		info->map.east_path = ft_strdup(split[1]);
	return (SUCCESS);
}

static int	parse_floor(t_info *info, char **split)
{
	int	ret;

	if (check_split_len(split, 2) == false)
		return (ERR_FLOOR_INFO_LEN);
	ret = rgb_validation(split[1]);
	if (ret != SUCCESS)
		return (ret);
	if (ft_strcmp(split[0], FLOOR) == 0)
		info->map.floor_color = rgb_to_int(split[1]);
	else if (ft_strcmp(split[0], CEILLING) == 0)
		info->map.ceilling_color = rgb_to_int(split[1]);
	return (SUCCESS);
}

static int	parse_handling(t_info *info, char **split, int fd)
{
	if (ft_strcmp(split[0], "\n") == 0)
		return (SUCCESS);
	if (is_wall(split[0]) == true)
		return (parse_wall(info, split));
	if (is_floor(split[0]) == true)
		return (parse_floor(info, split));
	if (is_map(split[0]) == true)
		return (parse_map(info, split, fd));
	return (ERR_UNKNOWN_INFO);
}

static int	parse_loop(t_info *info, int fd)
{
	char	*line;
	char	**split;
	int		ret;

	ret = SUCCESS;
	while (ret == SUCCESS)
	{
		line = remove_n(get_next_line(fd));
		if (line == NULL)
			break ;
		split = ft_split(line, ' ');
		ret = parse_handling(info, split, fd);
		free(line);
		ft_split_free(split);
	}
	return (ret);
}

int	parse(t_info *info, char *file_path)
{
	int		fd;

	if (check_extension(file_path) == false)
		return (ERR_NOT_CUB);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (ERR_CUB_FILE_OPEN);
	return (parse_loop(info, fd));
}