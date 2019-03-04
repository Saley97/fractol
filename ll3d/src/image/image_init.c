/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 05:34:33 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/13 23:21:14 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

t_image	*image_init(t_mlx *mlx, const int x, const int y)
{
	t_image	*img;

	if (!(img = ft_memalloc(sizeof(t_image))))
		return (NULL);
	if (!(img->image = mlx_new_image(mlx->mlx, x, y)))
	{
		free(img);
		return (NULL);
	}
	img->x = x;
	img->y = y;
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->str, &img->end);
	img->bpp /= 8;
	return (img);
}
