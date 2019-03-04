/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precalc_m.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 18:58:48 by edraugr-          #+#    #+#             */
/*   Updated: 2019/03/04 09:18:08 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	precalc_helper(t_vec3 *z, const t_fconf *f, const double r)
{
	double	r_1;

	r_1 = 0;
	if (f->precalc_m == PRECALC_M_HRS)
	{
		r_1 = (double)(1.0 / r);
		vec3_set(z, r_1 * ((z->x - z->y) * (z->x + z->y)),
			r_1 * z->x * z->y * 2, z->z);
	}
	else if (f->precalc_m == PRECALC_M_CRN)
		vec3_set(z, z->x + f->m_x * sin(tan(3 * z->y)),
			z->y + f->m_y * sin(tan(3 * z->x)), z->z);
	else if (f->precalc_m == PRECALC_M_PDJ)
		vec3_set(z, sin(f->m_x * z->y) - cos(f->m_y * z->x),
			sin(f->m_x * z->x) - cos(f->m_y * z->y), z->z);
}

void		precalc_m(t_vec3 *z, const t_fconf *f, const double r,
				const double r2)
{
	if (f->precalc_m == PRECALC_M_STD)
		return ;
	if (f->precalc_m == PRECALC_M_SIN)
		vec3_set(z, sin(z->x), sin(z->y), sin(z->z));
	else if (f->precalc_m == PRECALC_M_ABS)
		vec3_set(z, fabs(z->x), fabs(z->y), fabs(z->z));
	else if (f->precalc_m == PRECALC_M_SPH)
		vec3_set(z, (double)(z->x / r2), (double)(z->y / r2),
			(double)(z->z / r2));
	else if (f->precalc_m == PRECALC_M_SINR)
		vec3_set(z, z->x * sin(r2), z->y * sin(r2), z->z * sin(r2));
	else if (f->precalc_m == PRECALC_M_SWR)
		vec3_set(z, z->x * sin(r2) - z->y * cos(r2),
			z->x * cos(r2) + z->y * sin(r2), z->z * sin(r2));
	else
		precalc_helper(z, f, r);
}
