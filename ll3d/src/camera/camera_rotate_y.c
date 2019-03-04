/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotate_y.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 06:33:58 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/19 19:08:26 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

void	camera_rotate_y(t_cam *cam, const double a)
{
	t_mtx4	*tmp;
	t_mtx4	*mr;

	if (!(tmp = mtx4_copy(cam->cam)))
		return ;
	if (!(mr = mtx4_get_rotation(0, 1, 0, a * cam->sence)))
		return ;
	mtx4x3_mult(tmp, mr, cam->cam);
	free(tmp);
}
