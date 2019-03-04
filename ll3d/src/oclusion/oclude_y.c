/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oclude_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 00:28:32 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/04 09:12:01 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

static void	oclude_y_1(t_vec2 *d1, t_vec2 *d2)
{
	if (d1->x > SCREEN_X)
	{
		d1->y = d2->y - (int)((double)
			((d2->y - d1->y) * (SCREEN_X - d2->x))
			/ (double)(d2->x - d1->x));
		d1->x = SCREEN_X;
	}
	if (d2->x < 0)
	{
		d2->y = d2->y + (int)((double)
			((d2->y - d1->y) * d2->x)
			/ (double)(d1->x - d2->x));
		d2->x = 0;
	}
	if (d1->x < 0)
	{
		d1->y = d2->y + (int)((double)
			((d2->y - d1->y) * d2->x)
			/ (double)(d1->x - d2->x));
		d1->x = 0;
	}
}

void		oclude_y(t_vec2 *d1, t_vec2 *d2)
{
	if ((d1->x > 0 && d2->x < SCREEN_X)
		&& (d2->x > 0 && d2->x < SCREEN_X))
		return ;
	if (ft_abs(d2->y - d1->y) <= 2)
	{
		if (d1->x < 0 || d1->x > SCREEN_X)
			d1->x = ((d1->x < 0) ? 0 : SCREEN_X);
		if (d2->x < 0 || d2->x > SCREEN_X)
			d2->x = ((d2->x < 0) ? 0 : SCREEN_X);
		return ;
	}
	if (d2->x > SCREEN_X)
	{
		d2->y = d2->y + (int)((double)
			((d2->y - d1->y) * (SCREEN_X - d2->x))
			/ (double)(d2->x - d1->x));
		d2->x = SCREEN_X;
	}
	oclude_y_1(d1, d2);
}
