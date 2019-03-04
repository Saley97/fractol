/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_ll3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 07:10:16 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/04 02:07:22 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

t_mlx	*mlx_free_ll3d(t_mlx **mlx)
{
	if (!mlx)
		return (NULL);
	if (((*mlx)->mlx))
		ft_memdel((void **)&((*mlx)->mlx));
	if (((*mlx)->win))
		ft_memdel((void **)&((*mlx)->win));
	if (((*mlx)->image))
		image_free(&(*mlx)->image);
	ft_memdel((void **)mlx);
	return (*mlx);
}

t_mlx	*mlx_init_ll3d(const int width, const int height, char *header)
{
	t_mlx	*res;

	if (!(res = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	res->width = width;
	res->height = height;
	res->mlx = NULL;
	res->win = NULL;
	res->image = NULL;
	if (!(res->mlx = mlx_init()) ||
		!(res->win = mlx_new_window(res->mlx, width, height, header)) ||
		!(res->image = image_init(res, width, height)))
		return (mlx_free_ll3d(&res));
	return (res);
}
