/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_sum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 05:10:55 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/13 23:26:17 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

t_vec3	*vec3_sum(const t_vec3 *v1, const t_vec3 *v2)
{
	t_vec3	*vr;

	if (!(vr = vec3_init()))
		return (NULL);
	vr->x = v1->x + v2->x;
	vr->y = v1->y + v2->y;
	vr->z = v1->z + v2->z;
	return (vr);
}
