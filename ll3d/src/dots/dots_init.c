/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 05:28:28 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/13 23:20:24 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

t_dots	*dots_init(const int x, const int y)
{
	t_dots	*res;

	if (!(res = (t_dots *)malloc(sizeof(t_dots))))
		return (NULL);
	res->wb = NULL;
	res->cb = NULL;
	res->sb = NULL;
	res->xc = x;
	res->yc = y;
	res->zmin = INT32_MAX;
	res->zmax = INT32_MIN;
	res->cm = 0;
	return (res);
}
