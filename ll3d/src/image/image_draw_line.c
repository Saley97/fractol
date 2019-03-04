/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_draw_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 07:50:40 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/04 09:10:43 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"
#include <stdio.h>

static int	image_draw_line_1(t_mlx const *mlx, int *t)
{
	t[16] = t[10];
	t[17] = t[12];
	if ((t[6] = t[11] - t[10]) >= 0)
		t[9] = 1;
	else
	{
		t[9] = -1;
		t[6] = -t[6];
	}
	if ((t[7] = t[13] - t[12]) == 0)
	{
		while (t[6]-- != 0)
		{
			t[10] += t[9];
			image_set_pixel(mlx->image, t[10], t[12], color_lerp(t[14], t[15],
			(double)ft_fabs(t[10] - t[16]) / ft_fabs(t[11] - t[16])));
		}
		return (0);
	}
	return (1);
}

static int	image_draw_line_2(t_mlx const *mlx, int *t)
{
	if (t[6] == 0)
	{
		++t[12];
		image_set_pixel(mlx->image, t[10], t[12], color_lerp(t[14], t[15],
			(double)ft_fabs(t[12] - t[17]) / ft_fabs(t[13] - t[17])));
		while (--t[7] != 0)
		{
			++t[12];
			image_set_pixel(mlx->image, t[10], t[12], color_lerp(t[14], t[15],
				(double)ft_fabs(t[12] - t[17]) / ft_fabs(t[13] - t[17])));
		}
		return (0);
	}
	return (1);
}

static int	image_draw_line_3(t_mlx const *mlx, int *t)
{
	if (t[6] == t[7])
	{
		t[10] += t[9];
		++t[12];
		image_set_pixel(mlx->image, t[10], t[12], color_lerp(t[14], t[15],
			(double)ft_fabs(t[10] - t[16]) / ft_fabs(t[11] - t[16])));
		while (--t[7] != 0)
		{
			t[10] += t[9];
			++t[12];
			image_set_pixel(mlx->image, t[10], t[12], color_lerp(t[14], t[15],
			(double)ft_fabs(t[10] - t[16]) / ft_fabs(t[11] - t[16])));
		}
		return (0);
	}
	return (1);
}

static int	image_draw_line_4(t_mlx const *mlx, int *t,
				unsigned short *dt)
{
	dt[2] = 0;
	dt[0] = 8;
	dt[5] = 255;
	if (t[7] > t[6])
	{
		dt[1] = ((unsigned long)t[6] << 16) / (unsigned long)t[7];
		while (--t[7])
		{
			dt[3] = dt[2];
			dt[2] += dt[1];
			if (dt[2] <= dt[3])
				t[10] += t[9];
			++t[12];
			dt[4] = dt[2] >> dt[0];
			image_set_pixel(mlx->image, t[10], t[12], color_set_br(
				color_lerp(t[14], t[15], (double)ft_fabs(t[10] - t[16]) /
				ft_fabs(t[11] - t[16])), (255.0f - dt[4]) / 255.0f));
			image_set_pixel(mlx->image, t[10] + t[9], t[12], color_set_br(
				color_lerp(t[14], t[15], (double)ft_fabs(t[10] - t[16]) /
				ft_fabs(t[11] - t[16])), (255.0f - (dt[4] ^ dt[5])) / 255.0f));
		}
		image_set_pixel(mlx->image, t[11], t[13], t[15]);
		return (0);
	}
	return (1);
}

int			image_draw_line(t_mlx const *mlx, t_vec2 const *v1,
				t_vec2 const *v2, t_vec2 const *c)
{
	unsigned short	dt[6];
	int				t[18];

	ft_bzero(&dt, 6 * sizeof(short));
	ft_bzero(&t, 18 * 4);
	t[10] = v1->x;
	t[11] = v2->x;
	t[12] = v1->y;
	t[13] = v2->y;
	t[14] = c->x;
	t[15] = c->y;
	if (t[12] > t[13])
	{
		ft_swap(&t[10], &t[11]);
		ft_swap(&t[12], &t[13]);
		ft_swap(&t[14], &t[15]);
	}
	image_set_pixel(mlx->image, t[10], t[12], t[14]);
	if (!image_draw_line_1(mlx, &t[0]) ||
		!image_draw_line_2(mlx, &t[0]) ||
		!image_draw_line_3(mlx, &t[0]) ||
		!image_draw_line_4(mlx, &t[0], &dt[0]))
		return (0);
	return (image_draw_line2(mlx, &t[0], &dt[0]));
}
