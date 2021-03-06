/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_eq.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 18:17:10 by edraugr-          #+#    #+#             */
/*   Updated: 2019/03/01 18:19:38 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

int	vec3_eq(const t_vec3 *v1, const t_vec3 *v2)
{
	if (v1->x != v2->x)
		return (0);
	if (v1->y != v2->y)
		return (0);
	if (v1->z != v2->z)
		return (0);
	return (1);
}
