/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_draw_line2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 23:57:11 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/04 09:09:05 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

int	image_draw_line2(const t_mlx *mlx, int *t,
				unsigned short *dt)
{
	dt[1] = ((unsigned long)t[7] << 16) / (unsigned long)t[6];
	while (--t[6])
	{
		dt[3] = dt[2];
		dt[2] += dt[1];
		(dt[2] <= dt[3] ? t[12]++ : 0);
		t[10] += t[9];
		dt[4] = dt[2] >> dt[0];
		image_set_pixel(mlx->image, t[10], t[12], color_set_br(color_lerp(
			t[14], t[15], (double)ft_fabs(t[10] - t[16]) / ft_fabs(t[11] -
			t[16])), (255.0f - dt[4]) / 255.0f));
		image_set_pixel(mlx->image, t[10], t[12] + 1, color_set_br(color_lerp(
			t[14], t[15], (double)ft_fabs(t[10] - t[16]) / ft_fabs(t[11] -
			t[16])), (255.0f - (dt[4] ^ dt[5])) / 255.0f));
	}
	image_set_pixel(mlx->image, t[11], t[13], t[15]);
	return (0);
}
