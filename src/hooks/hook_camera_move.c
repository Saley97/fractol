/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_camera_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 00:09:16 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/01 21:41:48 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	hook_camera_move_x(t_cam *cam, double const a)
{
	camera_move_x(cam, a);
}

void	hook_camera_move_y(t_cam *cam, double const a)
{
	camera_move_y(cam, a);
}

void	hook_camera_move_z(t_cam *cam, double const a)
{
	camera_move_z(cam, a);
}
