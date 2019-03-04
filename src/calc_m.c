/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_m.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 19:15:05 by edraugr-          #+#    #+#             */
/*   Updated: 2019/03/01 19:22:44 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	calc_m(t_vec3 *z, const t_fconf *f)
{
	double	x2;
	double	y2;
	double	z2;

	x2 = z->x * z->x;
	y2 = z->y * z->y;
	z2 = z->z * z->z;
	if (f->calc_m == CALC_M_2)
		vec3_set(z, x2 - y2 - z2, 2 * z->y * z->x, 2 * z->z * z->x);
	else if (f->calc_m == CALC_M_3)
		vec3_set(z,
			z->x * (x2 - 3 * (y2 + z2)),
			-z->y * (y2 + 3 * (z2 - x2)),
			-z->z * (z2 + 3 * (y2 - x2)));
}
