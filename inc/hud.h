/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanghyki <kanghyki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 00:01:19 by kanghyki          #+#    #+#             */
/*   Updated: 2022/12/11 00:09:10 by kanghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUD_H
# define HUD_H

# include "img.h"

typedef struct s_pistol
{
	int				width;
	int				height;
	struct s_img	img;
}	t_pistol;

typedef struct s_crosshair
{
	struct s_img	img;
}	t_crosshair;

typedef struct s_hud
{
	struct s_pistol		pistol;
	struct s_crosshair	crosshair;
}	t_hud;

#endif
