/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_wheel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 23:09:30 by edraugr-          #+#    #+#             */
/*   Updated: 2019/02/18 21:53:38 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int	hook_weel_up(t_mouse *mouse)
{
	if (mouse->cam->focus >= 100.0f)
		return (0);
	mouse->cam->focus += 0.1f;
	return (0);
}

static int	hook_weel_down(t_mouse *mouse)
{
	if (mouse->cam->focus <= 0.1f)
		return (0);
	mouse->cam->focus -= 0.1f;
	return (0);
}

int			hook_wheel(int key, int x, int y, t_mouse *m)
{
	x = y;
	y = x;
	if (key == 4)
		return (hook_weel_up(m));
	else if (key == 5)
		return (hook_weel_down(m));
	return (0);
}
