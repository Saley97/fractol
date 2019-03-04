/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_station.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 04:25:20 by edraugr-          #+#    #+#             */
/*   Updated: 2019/03/04 09:17:34 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

/*
**	It`s not real play_station, sorry :c
*/

static int	image_get_pixel(const t_image *img, int x, int y)
{
	int	p;
	int	*im;

	x -= SCREEN_X / 2;
	y -= SCREEN_Y / 2;
	if (x < -img->x / 2.0f || x >= img->x / 2.0f || y < -img->y / 2.0f ||
		y >= img->y / 2.0f)
		return (0);
	p = (int)((x + img->x / 2.0f) + (y + img->y / 2.0f) * img->x) * img->bpp;
	im = (int *)(img->ptr + p);
	return (*im);
}

static int	get_smooth_cl(const t_image *img, const int x, const int y, int i)
{
	int	res;

	res = image_get_pixel(img, x, y);
	while (i > 0)
	{
		res = color_lerp(res, image_get_pixel(img, x + i, y), 0.5);
		res = color_lerp(res, image_get_pixel(img, x - i, y), 0.5);
		res = color_lerp(res, image_get_pixel(img, x, y + i), 0.5);
		res = color_lerp(res, image_get_pixel(img, x, y - i), 0.5);
		res = color_lerp(res, image_get_pixel(img, x + 1, y + i), 0.5);
		res = color_lerp(res, image_get_pixel(img, x + 1, y - i), 0.5);
		res = color_lerp(res, image_get_pixel(img, x - 1, y + i), 0.5);
		res = color_lerp(res, image_get_pixel(img, x - 1, y - i), 0.5);
		i--;
	}
	return (res);
}

void		play_station_on(const t_mouse *m, int itter)
{
	t_image	*tmp;
	int		i;
	int		j;

	tmp = image_init(m->mlx, SCREEN_X, SCREEN_Y);
	i = -1;
	while (++i < SCREEN_Y)
	{
		j = -1;
		while (++j < SCREEN_X)
			image_set_pixel(tmp, j - SCREEN_X / 2, i - SCREEN_Y / 2,
				get_smooth_cl(m->mlx->image, j, i, itter));
	}
	image_free(&(m->mlx->image));
	m->mlx->image = tmp;
}
