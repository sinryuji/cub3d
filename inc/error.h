/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 12:51:11 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/11 13:12:20 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdlib.h>
# include <unistd.h>

# include "../lib/libft/include/libft.h"

# define ERR_ARGC_MSG ("Invalid argumnet count\n")
# define ERR_OPEN_MSG ("File open failed\n")
# define ERR_CUB_MSG ("Not cub file\n")

enum e_error
{
	SUCCESS = 0,
	ERR_ARGC,
	ERR_FILE_OPEN,
	ERR_NOT_CUB
};

#endif
