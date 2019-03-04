/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:21:58 by edraugr-          #+#    #+#             */
/*   Updated: 2019/03/04 09:16:51 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static t_cam	*camera_default(void)
{
	t_cam *res;

	if (!(res = camera_init()))
		return (NULL);
	return (res);
}

static t_cam	*camera_setup(t_cam **cam)
{
	if (!(*cam = camera_default()))
		return (NULL);
	(*cam)->focus = 4;
	(*cam)->piv = vec3_new(0, 0, 0);
	return (*cam);
}

static void		default_init(t_mlx **mlx, t_cam **cam,
	t_mouse **mouse)
{
	*mlx = NULL;
	*cam = NULL;
	*mouse = NULL;
}

int				main(int argc, char **v)
{
	t_mlx		*mlx;
	t_cam		*cam;
	t_mouse		*mouse;
	t_fconf		f;

	if (argc != 2 || (ft_strcmp(v[1], "MANDEL") != 0
		&& ft_strcmp(v[1], "JULY") != 0 && ft_strcmp(v[1], "SHIP") != 0))
	{
		write(1, "usage: ./fractol MANDEL or JULY or SHIP\n", 40);
		exit(0);
	}
	default_init(&mlx, &cam, &mouse);
	if (!(mlx = mlx_init_ll3d(SCREEN_X, SCREEN_Y, SCREEN_NAME)) ||
		!(cam = camera_setup(&cam)) ||
		!(mouse = mouse_init(mlx, cam, &f)))
		exit(free_helper(&mlx, &cam, &mouse));
	set_frac(&f, v[1]);
	redraw(mouse);
	mlx_hook(mlx->win, 4, 0, hook_mouse_down, mouse);
	mlx_hook(mlx->win, 6, 0, hook_mouse_move, mouse);
	mlx_hook(mlx->win, 2, 0, hook_key, mouse);
	mlx_loop(mlx->mlx);
	return (0);
}
