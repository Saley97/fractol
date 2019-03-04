/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_camera_change.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 00:10:42 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/21 08:30:40 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	hook_camera_change_speed(t_cam *cam, double const a)
{
	cam->speed += a * CAM_SP;
}

void	hook_camera_change_sence(t_cam *cam, double const a)
{
	cam->sence += a * CAM_SE;
}

void	hook_camera_change_focus(t_cam *cam, double const a)
{
	if (a > 0)
		cam->focus = (double)((double)cam->focus / (double)2.0);
	else
		cam->focus *= 2.0;
}
