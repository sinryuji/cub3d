/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 12:52:37 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/13 16:33:25 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/error.h"

static char	*get_err_msg_01(int err)
{
	if (err == ERR_ARGC)
		return (ERR_ARGC_MSG);
	else if (err == ERR_CUB_FILE_OPEN)
		return (ERR_CUB_OPEN_MSG);
	else if (err == ERR_TEX_FILE_OPEN)
		return (ERR_TEX_OPEN_MSG);
	else if (err == ERR_NOT_CUB)
		return (ERR_CUB_MSG);
	else if (err == ERR_WALL_INFO_LEN)
		return (ERR_WALL_INFO_LEN_MSG);
	else if (err == ERR_FLOOR_INFO_LEN)
		return (ERR_FLOOR_INFO_LEN_MSG);
	else if (err == ERR_RGB_LEN)
		return (ERR_RGB_LEN_MSG);
	else if (err == ERR_RGB_VAL)
		return (ERR_RGB_VAL_MSG);
	else if (err == ERR_RGB_RANGE)
		return (ERR_RGB_RANGE_MSG);
	else if (err == ERR_UNKNOWN_INFO)
		return (ERR_UNKNOWN_MSG);
	else if (err == ERR_NO_PLAYER)
		return (ERR_NO_PLAYER_MSG);
	else if (err == ERR_NOT_CLOSED_MAP)
		return (ERR_NOT_CLOSED_MAP_MSG);
	return (NULL);
}

static char	*get_err_msg_02(int err)
{
	if (err == ERR_DUP_PLAYER)
		return (ERR_DUP_PLAYER_MSG);
	else if (err == ERR_EMPTY_INFO)
		return (ERR_EMPTH_INFO_MSG);
	else if (err == ERR_DUP_INFO)
		return (ERR_DUP_INFO_MSG);
	return (NULL);
}

void	put_err_exit(int err)
{
	char	*err_msg;	

	if (err == SUCCESS)
		return ;
	if (err < 13)
		err_msg = get_err_msg_01(err);
	else
		err_msg = get_err_msg_02(err);
	write(STDERR_FILENO, err_msg, ft_strlen(err_msg));
	exit(EXIT_FAILURE);
}
