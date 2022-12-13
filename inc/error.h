/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 12:51:11 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/13 15:32:07 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdlib.h>
# include <unistd.h>

# include "../lib/libft/include/libft.h"

# define ERR_ARGC_MSG "Error\nInvalid argumnet count\n"
# define ERR_CUB_OPEN_MSG "Error\nCub file open failed\n"
# define ERR_TEX_OPEN_MSG "Error\nTexture file open failed\n"
# define ERR_CUB_MSG "Error\nNot cub file\n"
# define ERR_WALL_INFO_LEN_MSG "Error\nInvalid wall information count\n"
# define ERR_FLOOR_INFO_LEN_MSG "Error\nInvalid floor information count\n"
# define ERR_RGB_LEN_MSG "Error\nInvalid rgb information count\n"
# define ERR_RGB_VAL_MSG "Error\nInvalid rgb value\n"
# define ERR_RGB_RANGE_MSG "Error\nInvalid rgb value range\n"
# define ERR_UNKNOWN_MSG "Error\nUnknown information type\n"
# define ERR_NO_PLAYER_MSG "Error\nNo player on the map\n"
# define ERR_NOT_CLOSED_MAP_MSG "Error\nThis map is not closed\n"
# define ERR_DUP_PLAYER_MSG "Error\nCub3d must have only one player\n"

enum e_error
{
	SUCCESS = 0,
	ERR_ARGC,
	ERR_CUB_FILE_OPEN,
	ERR_TEX_FILE_OPEN,
	ERR_NOT_CUB,
	ERR_WALL_INFO_LEN,
	ERR_FLOOR_INFO_LEN,
	ERR_RGB_LEN,
	ERR_RGB_VAL,
	ERR_RGB_RANGE,
	ERR_UNKNOWN_INFO,
	ERR_NO_PLAYER,
	ERR_NOT_CLOSED_MAP,
	ERR_DUP_PLAYER
};

#endif
