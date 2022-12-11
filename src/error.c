/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 12:52:37 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/11 16:57:58 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/error.h"

static char	*get_err_msg(int err)
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
	else if (err == ERR_UNKNOWN_INFO)
		return (ERR_UNKNOWN_MSG);
	return (NULL);
}

void	put_err_exit(int err)
{
	char	*err_msg;	

	if (err == SUCCESS)
		return ;
	err_msg = get_err_msg(err);
	write(STDERR_FILENO, err_msg, ft_strlen(err_msg));
	exit(EXIT_FAILURE);
}
