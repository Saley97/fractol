/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_m.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 18:42:01 by edraugr-          #+#    #+#             */
/*   Updated: 2019/03/02 17:34:35 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	set_m(t_vec3 *p, const t_fconf *f, const double r2)
{
	if (f->type == JUL_MODE)
		vec3_set(p, f->m_x, f->m_y, p->z);
	if (f->set_m == SET_M_STD)
		return ;
	if (f->set_m == SET_M_MTX)
	{
		vec3_set(p,
			p->x * f->coef[0][0] + p->y * f->coef[0][1] + p->z * f->coef[0][1],
			p->x * f->coef[1][0] + p->y * f->coef[1][1] + p->z * f->coef[1][1],
			p->x * f->coef[2][0] + p->y * f->coef[2][1] + p->z * f->coef[2][2]);
		return ;
	}
	if (f->set_m == SET_M_SPH)
	{
		vec3_set(p, (double)(p->x / r2), (double)(p->y / r2),
			(double)(p->z / r2));
		return ;
	}
	if (f->set_m == SET_M_SIN)
		vec3_set(p, sin(p->x), sin(p->y), sin(p->z));
}
