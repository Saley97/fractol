/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx4_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:13:05 by edraugr-          #+#    #+#             */
/*   Updated: 2019/02/13 23:22:55 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

t_mtx4	*mtx4_copy(const t_mtx4 *src)
{
	t_mtx4	*res;
	int		i;
	int		j;

	if (!(res = mtx4_init(0)))
		return (NULL);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			res->val[i][j] = src->val[i][j];
	}
	return (res);
}
