/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oclusion_draw_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 00:33:46 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/04 09:13:04 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

void	oclusion_draw_line(const t_mlx *c, t_dots *d,
	int d1, int d2)
{
	t_vec2	*v1;
	t_vec2	*v2;
	t_vec2	*cv;

	if (check_out(d, d1, d2))
		return ;
	v1 = vec2_new(d->sb[d1]->x + SCREEN_X / 2, d->sb[d1]->y + SCREEN_Y / 2);
	v2 = vec2_new(d->sb[d2]->x + SCREEN_X / 2, d->sb[d2]->y + SCREEN_Y / 2);
	cv = vec2_new((int)(d->wb[d1]->w) & 0xFFFFFF,
		(int)(d->wb[d2]->w) & 0xFFFFFF);
	if (d->cb[d1]->z > d->cb[d2]->z)
		oclude_z(v1, v2, d->cb[d1]->z, d->cb[d2]->z);
	else
		oclude_z(v2, v1, d->cb[d2]->z, d->cb[d1]->z);
	swap_if_d2_less(&v1, &v2, (double)v2->x, (double)v1->x);
	oclude_x(v1, v2);
	swap_if_d2_less(&v1, &v2, (double)v2->y, (double)v1->y);
	oclude_y(v1, v2);
	vec2_set(v1, v1->x - SCREEN_X / 2, v1->y - SCREEN_Y / 2);
	vec2_set(v2, v2->x - SCREEN_X / 2, v2->y - SCREEN_Y / 2);
	image_draw_line(c, v1, v2, cv);
	free(cv);
	free(v1);
	free(v2);
}
