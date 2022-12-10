/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanghyki <kanghyki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:54:27 by kanghyki          #+#    #+#             */
/*   Updated: 2022/12/10 22:18:04 by kanghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_IMG_H
# define MLX_IMG_H

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_line;
	int		bpp;
	int		img_width;
	int		img_height;
	int		endian;
}	t_img;

#endif
