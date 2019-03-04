/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_camera_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 00:39:49 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/04 09:15:54 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdio.h>

void	hook_camera_rotate_x(t_cam *cam, double const a)
{
	t_vec3	*axis;

	axis = vec3_new(cam->cam->val[0][0], cam->cam->val[0][1],
		cam->cam->val[0][2]);
	camera_rotate_custom(cam, cam->piv, axis, a);
	free(axis);
}

void	hook_camera_rotate_y(t_cam *cam, double const a)
{
	t_vec3	*axis;

	axis = vec3_new(0, 1, 0);
	camera_rotate_custom(cam, cam->piv, axis, -a);
	free(axis);
}
