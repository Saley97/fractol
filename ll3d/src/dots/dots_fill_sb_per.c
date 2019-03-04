/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots_fill_sb_per.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 09:29:15 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/19 19:08:26 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

void	dots_fill_sb_per(const t_vec3 *point, t_vec2 *res, const t_cam *cam)
{
	double	a;
	double	b;

	a = cam->focus;
	b = a + point->z;
	if (ft_fabs(b) < 0.001f)
		b = 2.0f;
	res->x = a / b * point->x * cam->focus;
	res->y = a / b * point->y * cam->focus;
}
