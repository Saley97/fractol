/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots_fill_cb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 07:12:44 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/19 19:08:26 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

static double	dots_fill_cb_det(const double val[4][4])
{
	return (val[0][0] * val[1][1] * val[2][2] -
		val[0][0] * val[1][2] * val[2][1] +
		val[0][1] * val[1][2] * val[2][0] -
		val[0][1] * val[1][0] * val[2][2] +
		val[0][2] * val[1][0] * val[2][1] -
		val[0][2] * val[1][1] * val[2][0]);
}

static void		row_from_mtx(const double val[4][4], t_vec3 *v, const int c)
{
	v->x = val[c][0];
	v->y = val[c][1];
	v->z = val[c][2];
}

static void		row_to_mtx(double val[4][4], const t_vec3 *v, const int c)
{
	val[c][0] = v->x;
	val[c][1] = v->y;
	val[c][2] = v->z;
}

void			dots_fill_cb(const t_vec4 *p, const t_mtx4 *c, t_vec3 *res)
{
	t_mtx4	*m;
	t_vec3	*l;
	t_vec3	*t;

	m = (t_mtx4 *)c;
	l = vec3_new(p->x - c->val[3][0],
		p->y - c->val[3][1], p->z - c->val[3][2]);
	t = vec3_init();
	row_from_mtx(m->val, t, 0);
	row_to_mtx(m->val, l, 0);
	res->x = dots_fill_cb_det(m->val);
	row_to_mtx(m->val, t, 0);
	row_from_mtx(m->val, t, 1);
	row_to_mtx(m->val, l, 1);
	res->y = dots_fill_cb_det(m->val);
	row_to_mtx(m->val, t, 1);
	row_from_mtx(m->val, t, 2);
	row_to_mtx(m->val, l, 2);
	res->z = dots_fill_cb_det(m->val);
	row_to_mtx(m->val, t, 2);
	free(l);
	free(t);
}
