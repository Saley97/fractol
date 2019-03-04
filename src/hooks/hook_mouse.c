/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:30:44 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/04 13:48:45 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static inline void	calc_jul_coef(int x, int y, t_mouse *m)
{
	m->f->m_x = (double)((4.0 / (double)SCREEN_X) * (x - SCREEN_X / 2));
	m->f->m_y = (double)((4.0 / (double)SCREEN_Y) * (y - SCREEN_Y / 2));
}

int					hook_mouse_down(int key, int x, int y, t_mouse *mouse)
{
	t_vec2	*s_p;
	t_vec3	*w_p;

	if (key != KEY_M_L && key != KEY_M_R && key != KEY_M_M)
		return (0);
	if (key != KEY_M_M)
	{
		s_p = vec2_new(x, y);
		w_p = vec3_init();
		calc_world_from_screen(s_p, w_p, mouse->cam);
		mouse->cam->cam->val[3][0] =  (mouse->cam->cam->val[3][0] + w_p->x) / 2.0;
		mouse->cam->cam->val[3][1] = (mouse->cam->cam->val[3][1] + w_p->y) / 2.0;
		mouse->cam->cam->val[3][2] = (mouse->cam->cam->val[3][2]  + w_p->z) / 2.0;
		vec3_set(mouse->cam->piv, w_p->x, w_p->y, w_p->z);
		free(w_p);
		free(s_p);
		if (key == KEY_M_L)
			hook_camera_change_focus(mouse->cam, 1.0);
		if (key == KEY_M_R)
			hook_camera_change_focus(mouse->cam, -1.0);
	}
	else if (mouse->f->jul_change_m == JUL_CH_M_OFF)
		calc_jul_coef(x, y, mouse);
	redraw(mouse);
	return (0);
}

int					hook_mouse_move(int x, int y, t_mouse *mouse)
{
	if (mouse->f->jul_change_m == JUL_CH_M_ON)
	{
		calc_jul_coef(x, y, mouse);
		redraw(mouse);
	}
	return (0);
}
