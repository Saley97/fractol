/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_per_calc_piv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:36:29 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/04 09:00:18 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

static void inline	camera_pcv_val(t_vec3 *res, const double val[4][4],
	const double focus)
{
	res->x = val[3][0] - val[2][0] * focus;
	res->y = val[3][1] - val[2][1] * focus;
	res->z = val[3][2] - val[2][2] * focus;
}

void				camera_per_calc_piv(t_cam *cam)
{
	t_vec3	*res;

	res = vec3_init();
	camera_pcv_val(res, cam->cam->val, cam->focus);
	if (cam->piv)
		free(cam->piv);
	cam->piv = res;
}
