/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oclude_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 00:31:40 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/19 19:08:26 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

void	oclude_z(t_vec2 *d1, t_vec2 *d2, double z1, double z2)
{
	if (z1 > 0 && z2 > 0)
		return ;
	if (d2->y > d1->y)
		d2->y = d2->y + (int)((double)
			((d2->y - d1->y) * (z2))
			/ (double)(z1 - z2));
	else
		d2->y = d2->y + (int)((double)
			((d2->y - d1->y) * (z2))
			/ (double)(z1 - z2));
	if (d2->x > d1->x)
		d2->x = d2->x + (int)((double)
			((d2->x - d1->x) * z2)
			/ (double)(z1 - z2));
	else
		d2->x = d2->x + (int)((double)
			((d2->x - d1->x) * z2)
			/ (double)(z1 - z2));
}
