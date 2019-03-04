/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 05:11:54 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/19 19:08:26 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

t_vec4	*vec4_new(const double x, const double y, const double z,
	const double w)
{
	t_vec4	*vr;

	if (!(vr = vec4_init()))
		return (NULL);
	vr->x = x;
	vr->y = y;
	vr->z = z;
	vr->w = w;
	return (vr);
}
