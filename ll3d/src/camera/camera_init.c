/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 05:39:55 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/04 09:02:43 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

static void	camera_init_1(double val[4][4])
{
	val[0][0] = 1;
	val[0][1] = 0;
	val[0][2] = 0;
	val[0][3] = 0;
	val[1][0] = 0;
	val[1][1] = 1;
	val[1][2] = 0;
	val[1][3] = 0;
	val[2][0] = 0;
	val[2][1] = 0;
	val[2][2] = 1;
	val[2][3] = 0;
	val[3][0] = 0;
	val[3][1] = 0;
	val[3][2] = 0;
	val[3][3] = 1;
}

t_cam		*camera_init(void)
{
	t_cam	*res;

	if (!(res = (t_cam *)malloc(sizeof(t_cam))))
		return (NULL);
	res->cam = mtx4_init(0);
	camera_init_1(res->cam->val);
	res->mode = CAM_2D;
	res->focus = CAM_DFO;
	res->speed = CAM_DSP;
	res->sence = CAM_DSE;
	res->piv = NULL;
	return (res);
}
