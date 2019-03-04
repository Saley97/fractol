/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx4_get_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 06:36:53 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/19 19:08:26 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

t_mtx4		*mtx4_get_rotation(const double x, const double y, const double z,
	const double a)
{
	double	c;
	double	s;
	t_mtx4	*res;

	if (!(res = mtx4_init(0)))
		return (NULL);
	c = cosf(a * M_PI / 180);
	s = sinf(a * M_PI / 180);
	res->val[0][0] = c + (1 - c) * x * x;
	res->val[0][1] = (1 - c) * x * y + s * z;
	res->val[0][2] = (1 - c) * x * z - s * y;
	res->val[0][3] = 0;
	res->val[1][0] = (1 - c) * x * y - s * z;
	res->val[1][1] = c + (1 - c) * y * y;
	res->val[1][2] = (1 - c) * y * z + s * x;
	res->val[1][3] = 0;
	res->val[2][0] = (1 - c) * x * z + s * y;
	res->val[2][1] = (1 - c) * y * z - s * x;
	res->val[2][2] = c + (1 - c) * z * z;
	res->val[2][3] = 0;
	res->val[3][0] = 0;
	res->val[3][1] = 0;
	res->val[3][2] = 0;
	res->val[3][3] = 1;
	return (res);
}
