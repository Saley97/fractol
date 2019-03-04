/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_frac_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 20:04:03 by edraugr-          #+#    #+#             */
/*   Updated: 2019/03/04 08:55:04 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	control_helper(const int key, t_mouse *m)
{
	if (key == KEY_PLUS)
		m->f->coef[m->f->cur_coef / 3][m->f->cur_coef % 3] += 0.1;
	if (key == KEY_MINUS)
		m->f->coef[m->f->cur_coef / 3][m->f->cur_coef % 3] -= 0.1;
	if (key == KEY_C)
		fill_pallet(m->f);
	if (key == KEY_PLUS_R)
		if (m->f->cl_num < FRAC_DDP)
			m->f->cl_num++;
	if (key == KEY_MINUS_R)
		if (m->f->cl_num > 2)
			m->f->cl_num--;
	if (key == KEY_L)
		m->f->lerp_m = (m->f->lerp_m + 1) % 2;
	if (key == KEY_R)
		m->f->play_station_m = (m->f->play_station_m + 1) % 2;
	if (key == KEY_X)
		if (m->f->play_station_n < MAX_PS_N)
			m->f->play_station_n++;
	if (key == KEY_Z)
		if (m->f->play_station_n > 1)
			m->f->play_station_n--;
}

void		hook_frac_control(const int key, t_mouse *m)
{
	if (key == KEY_T)
		m->f->type = (m->f->type + 1) % 2;
	if (key == KEY_F)
		m->f->demen = (m->f->demen + 1) % 2;
	if (key == KEY_G)
		m->f->calc_m = (m->f->calc_m + 1) % 2;
	if (key == KEY_H)
		m->f->set_m = (m->f->set_m + 1) % 4;
	if (key == KEY_Y)
		m->f->precalc_m = (m->f->precalc_m + 1) % 9;
	if (key == KEY_0_U)
		m->f->cur_coef = (m->f->cur_coef + 1) % 9;
	if (key == KEY_9_U)
		m->f->cur_coef = (m->f->cur_coef - 1) % 9;
	if (key == KEY_V)
		m->f->jul_change_m = (m->f->jul_change_m + 1) % 2;
	if (key == KEY_I)
		m->f->info_m = (m->f->info_m + 1) % 2;
	control_helper(key, m);
	if (key == KEY_T || key == KEY_F || key == KEY_G || key == KEY_H
		|| key == KEY_Y || key == KEY_C || key == KEY_L || key == KEY_I
		|| key == KEY_R || key == KEY_X || key == KEY_Z || key == KEY_MINUS_R
		|| key == KEY_PLUS || key == KEY_MINUS || key == KEY_PLUS_R)
		redraw(m);
}
