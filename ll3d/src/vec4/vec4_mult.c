/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_mult.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 05:11:46 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/19 19:08:26 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

t_vec4	*vec4_mult(const t_vec4 *v, const double s)
{
	t_vec4	*vr;

	if (!(vr = vec4_init()))
		return (NULL);
	vr->x = v->x * s;
	vr->y = v->y * s;
	vr->z = v->z * s;
	vr->w = v->w * s;
	return (vr);
}
