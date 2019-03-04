/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx4x4_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 03:19:32 by edraugr-          #+#    #+#             */
/*   Updated: 2019/02/13 23:24:04 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

t_mtx4	*mtx4x4_mult(const t_mtx4 *a, const t_mtx4 *b, t_mtx4 *dst)
{
	int	c;
	int	r;
	int	i;

	mtx4_clear(dst);
	r = -1;
	while (++r < 4)
	{
		c = -1;
		while (++c < 4)
		{
			i = -1;
			while (++i < 4)
				dst->val[r][c] += a->val[r][i] * b->val[i][c];
		}
	}
	return (dst);
}
