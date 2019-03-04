/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx4_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 23:06:38 by edraugr-          #+#    #+#             */
/*   Updated: 2019/02/13 23:23:42 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"
#include <stdio.h>

void	mtx4_print(const t_mtx4 *src)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		printf("(");
		while (++j < 4)
		{
			printf(" %.6f ", src->val[i][j]);
		}
		printf(")\n");
	}
}
