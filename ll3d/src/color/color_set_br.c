/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_set_br.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 23:49:12 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/04 09:03:45 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

int	color_set_br(const int c, double br)
{
	int	r;
	int	g;
	int	b;

	if (br > 1)
		br = 1;
	r = ((c & 0xFF0000) >> 16) * br;
	g = ((c & 0xFF00) >> 8) * br;
	b = (c & 0xFF) * br;
	return (r << 16 | g << 8 | b);
}
