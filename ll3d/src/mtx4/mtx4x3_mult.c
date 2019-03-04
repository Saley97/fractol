/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx4x3_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 04:12:52 by edraugr-          #+#    #+#             */
/*   Updated: 2019/02/13 23:23:53 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

t_mtx4	*mtx4x3_mult(const t_mtx4 *a, const t_mtx4 *b, t_mtx4 *dst)
{
	int	c;
	int	r;
	int	i;

	mtx4_clear(dst);
	r = -1;
	while (++r < 3)
	{
		c = -1;
		while (++c < 3)
		{
			i = -1;
			while (++i < 3)
				dst->val[r][c] += a->val[r][i] * b->val[i][c];
		}
	}
	i = -1;
	while (++i < 4)
	{
		dst->val[i][3] = a->val[i][3];
		dst->val[3][i] = a->val[3][i];
	}
	return (dst);
}
