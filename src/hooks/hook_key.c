/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 22:44:24 by edraugr-          #+#    #+#             */
/*   Updated: 2019/03/04 08:31:50 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int			hook_esc(t_mouse *mouse)
{
	exit(free_helper(&(mouse->mlx), &(mouse->cam), &mouse));
}

static void inline	hook_key_change(const int key, t_mouse *mouse)
{
	if (key == KEY_1)
		hook_camera_change_speed(mouse->cam, -1);
	if (key == KEY_4)
		hook_camera_change_speed(mouse->cam, 1);
	if (key == KEY_2)
		hook_camera_change_sence(mouse->cam, -1);
	if (key == KEY_5)
		hook_camera_change_sence(mouse->cam, 1);
	if (key == KEY_3)
		hook_camera_change_focus(mouse->cam, -1);
	if (key == KEY_6)
		hook_camera_change_focus(mouse->cam, 1);
	if (key == KEY_3 || key == KEY_6)
		redraw(mouse);
}

static void inline	hook_key_rotate(const int key, t_mouse *mouse)
{
	if (key != KEY_ARROWU && key != KEY_ARROWD
		&& key != KEY_ARROWL && key != KEY_ARROWR)
		return ;
	if (key == KEY_ARROWU)
		hook_camera_rotate_x(mouse->cam, 1);
	else if (key == KEY_ARROWD)
		hook_camera_rotate_x(mouse->cam, -1);
	if (key == KEY_ARROWL)
		hook_camera_rotate_y(mouse->cam, -1);
	else if (key == KEY_ARROWR)
		hook_camera_rotate_y(mouse->cam, 1);
	redraw(mouse);
}

static void inline	hook_key_move(const int key, t_mouse *mouse)
{
	if (key == KEY_W)
		hook_camera_move_y(mouse->cam, -1.0);
	if (key == KEY_S)
		hook_camera_move_y(mouse->cam, 1.0);
	if (key == KEY_D)
		hook_camera_move_x(mouse->cam, 1.0);
	if (key == KEY_A)
		hook_camera_move_x(mouse->cam, -1.0);
	if (mouse->cam->mode == CAM_3D)
	{
		if (key == KEY_E)
			hook_camera_move_z(mouse->cam, 1.0);
		if (key == KEY_Q)
			hook_camera_move_z(mouse->cam, -1.0);
	}
	if (key == KEY_W || key == KEY_S || key == KEY_D
		|| key == KEY_A || key == KEY_E || key == KEY_Q)
		redraw(mouse);
}

int					hook_key(const int key, t_mouse *mouse)
{
	hook_key_move(key, mouse);
	if (mouse->f->demen == CAM_3D)
		hook_key_rotate(key, mouse);
	hook_key_change(key, mouse);
	hook_frac_control(key, mouse);
	mouse->cam->mode = mouse->f->demen;
	if (key == KEY_ESC)
		hook_esc(mouse);
	return (0);
}
