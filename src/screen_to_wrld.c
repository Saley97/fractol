/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_to_wrld.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 19:15:25 by edraugr-          #+#    #+#             */
/*   Updated: 2019/03/04 09:19:00 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	calc_3d(const t_vec2 *s_p, t_vec3 *dst, const t_cam *cam)
{
	double	dx;
	double	dy;
	double	dz;

	dx = (double)((double)cam->focus / (double)SCREEN_X)
		* (s_p->x - SCREEN_X / 2);
	dy = (double)((double)cam->focus / (double)SCREEN_X)
		* (s_p->y - SCREEN_Y / 2);
	dz = (double)((double)cam->focus / (double)SCREEN_X);
	dst->x = cam->cam->val[0][0] * dx + cam->cam->val[0][1] * dy
		+ cam->cam->val[0][2] * dz + cam->cam->val[3][0];
	dst->y = cam->cam->val[1][0] * dx + cam->cam->val[1][1] * dy
		+ cam->cam->val[1][2] * dz + cam->cam->val[3][1];
	dst->z = cam->cam->val[2][0] * dx + cam->cam->val[2][1] * dy
		+ cam->cam->val[2][2] * dz + cam->cam->val[3][2];
}

static void	calc_2d(const t_vec2 *s_p, t_vec3 *dst, const t_cam *cam)
{
	double	dx;
	double	dy;

	dx = (double)((double)cam->focus / (double)SCREEN_X)
		* (s_p->x - SCREEN_X / 2);
	dy = (double)((double)cam->focus / (double)SCREEN_X)
		* (s_p->y - SCREEN_Y / 2);
	dst->x = dx + cam->cam->val[3][0];
	dst->y = dy + cam->cam->val[3][1];
	dst->z = 0.0;
}

void		calc_world_from_screen(const t_vec2 *s_p, t_vec3 *dst,
				const t_cam *cam)
{
	if (cam->mode == CAM_2D)
		calc_2d(s_p, dst, cam);
	else
		calc_3d(s_p, dst, cam);
}
