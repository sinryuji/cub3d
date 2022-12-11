/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 12:52:37 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/11 13:12:29 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/error.h"

static char	*get_err_msg(int err)
{
	if (err == ERR_ARGC)
		return (ERR_ARGC_MSG);
	else if (err == ERR_FILE_OPEN)
		return (ERR_OPEN_MSG);
	else if (err == ERR_NOT_CUB)
		return (ERR_CUB_MSG);
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
