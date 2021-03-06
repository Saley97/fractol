/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move_y.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 05:51:00 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/04 08:59:41 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

static void	camera_move_y_1(double val[4][4], const double l)
{
	val[3][0] += val[1][0] * l;
	val[3][1] += val[1][1] * l;
	val[3][2] += val[1][2] * l;
}

void		camera_move_y(t_cam *cam, const double l)
{
	camera_move_y_1(cam->cam->val,
		(double)((double)cam->focus / (double)10) * l * cam->speed);
}
