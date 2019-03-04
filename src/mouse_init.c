/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:24:05 by edraugr-          #+#    #+#             */
/*   Updated: 2019/03/04 05:24:04 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_mouse	*mouse_init(t_mlx *mlx, t_cam *cam, t_fconf *f)
{
	t_mouse	*res;

	if (!(res = (t_mouse *)malloc(sizeof(t_mouse)))
		|| !(res->t = (t_threads *)malloc(sizeof(t_threads))))
		return (NULL);
	res->x = 0;
	res->y = 0;
	res->cam = cam;
	res->mlx = mlx;
	res->f = f;
	return (res);
}
