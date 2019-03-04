/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:17:26 by edraugr-          #+#    #+#             */
/*   Updated: 2019/03/04 09:33:36 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static char	*choose_mode1(const t_fconf *f)
{
	if (f->precalc_m == PRECALC_M_STD)
		return ("STD");
	if (f->precalc_m == PRECALC_M_SIN)
		return ("SIN");
	if (f->precalc_m == PRECALC_M_ABS)
		return ("ABS");
	if (f->precalc_m == PRECALC_M_SPH)
		return ("SPH");
	if (f->precalc_m == PRECALC_M_SINR)
		return ("SINR");
	if (f->precalc_m == PRECALC_M_SWR)
		return ("SWR");
	if (f->precalc_m == PRECALC_M_HRS)
		return ("HRS");
	if (f->precalc_m == PRECALC_M_CRN)
		return ("CRN");
	return ("PDJ");
}

static char	*choose_mode(const int flag, const t_fconf *f)
{
	if (flag == 0)
	{
		if (f->set_m == SET_M_STD)
			return ("STD");
		if (f->set_m == SET_M_MTX)
			return ("MTX");
		if (f->set_m == SET_M_SIN)
			return ("SIN");
		if (f->set_m == SET_M_SPH)
			return ("SPH");
	}
	if (flag == 1)
		return (choose_mode1(f));
	return (f->calc_m == CALC_M_2 ? "Z^2" : "Z^3");
}

static void	put_camera_info1(const t_mlx *mlx, t_fconf const *f)
{
	char	a[1024];

	sprintf(a, "CUR_COEF:  x = %d  y = %d  (keys 9 0 - =)",
		f->cur_coef % 3, f->cur_coef / 3);
	mlx_string_put(mlx->mlx, mlx->win, 15, 280, COLOR_BLACK, a);
	sprintf(a, "JUL_COEF:  x = %.3f  y = %.3f  (mouse 3)", f->m_x, f->m_y);
	mlx_string_put(mlx->mlx, mlx->win, 15, 300, COLOR_BLACK, a);
	sprintf(a, "LETP_MODE: %s (key l)", f->lerp_m == LERP_M_ON ? "on" : "off");
	mlx_string_put(mlx->mlx, mlx->win, 15, 320, COLOR_BLACK, a);
	sprintf(a, "COLOR_NUM:  %d  (keys num + -, p)", f->cl_num);
	mlx_string_put(mlx->mlx, mlx->win, 15, 340, COLOR_BLACK, a);
	sprintf(a, "PLAY_STATION_MODE:  %s  (k = %d)  (keys x, z, r)",
		f->play_station_m == PS_M_ON ? "on" : "off", f->play_station_n);
	mlx_string_put(mlx->mlx, mlx->win, 15, 360, COLOR_BLACK, a);
	sprintf(a, "JUL_LOCK: %s (key v)", f->jul_change_m == JUL_CH_M_ON ?
		"on" : "off");
	mlx_string_put(mlx->mlx, mlx->win, 15, 380, COLOR_BLACK, a);
	sprintf(a, "C_DOTS_MODE: %s (key t)", f->type == JUL_MODE ?
		"JUL" : "MANDEL");
	mlx_string_put(mlx->mlx, mlx->win, 15, 400, COLOR_BLACK, a);
}

static void	put_camera_info(const t_mlx *mlx, t_cam const *cam,
	t_fconf const *f)
{
	char	a[1024];

	sprintf(a, "FRAC MATRIX:");
	mlx_string_put(mlx->mlx, mlx->win, 15, 50, COLOR_BLACK, a);
	sprintf(a, "%.3f %.3f %.3f", f->coef[0][0], f->coef[0][1], f->coef[0][2]);
	mlx_string_put(mlx->mlx, mlx->win, 15, 70, COLOR_BLACK, a);
	sprintf(a, "%.3f %.3f %.3f", f->coef[1][0], f->coef[1][1], f->coef[1][2]);
	mlx_string_put(mlx->mlx, mlx->win, 15, 90, COLOR_BLACK, a);
	sprintf(a, "%.3f %.3f %.3f", f->coef[2][0], f->coef[2][1], f->coef[2][2]);
	mlx_string_put(mlx->mlx, mlx->win, 15, 110, COLOR_BLACK, a);
	sprintf(a, "CAM POS:");
	mlx_string_put(mlx->mlx, mlx->win, 15, 150, COLOR_BLACK, a);
	sprintf(a, "%.3f %.3f %.3f", cam->cam->val[3][0], cam->cam->val[3][1],
		cam->cam->val[3][2]);
	mlx_string_put(mlx->mlx, mlx->win, 15, 170, COLOR_BLACK, a);
	sprintf(a, "MODE:    %-7s   (key f)", cam->mode == CAM_2D ? "2D" : "3D");
	mlx_string_put(mlx->mlx, mlx->win, 15, 200, COLOR_BLACK, a);
	sprintf(a, "SET_MODE:   %s   (key h)", choose_mode(0, f));
	mlx_string_put(mlx->mlx, mlx->win, 15, 220, COLOR_BLACK, a);
	sprintf(a, "PRECALC_MODE:   %s   (key y)", choose_mode(1, f));
	mlx_string_put(mlx->mlx, mlx->win, 15, 240, COLOR_BLACK, a);
	sprintf(a, "CALC_MODE:   %s   (key g)", choose_mode(2, f));
	mlx_string_put(mlx->mlx, mlx->win, 15, 260, COLOR_BLACK, a);
	put_camera_info1(mlx, f);
}

void		redraw(t_mouse *m)
{
	image_clear(m->mlx->image);
	thread_img_filler(m);
	if (m->f->play_station_m == PS_M_ON)
		play_station_on(m, m->f->play_station_n);
	mlx_put_image_to_window(m->mlx->mlx, m->mlx->win,
		m->mlx->image->image, 0, 0);
	if (m->f->info_m == INFO_M_ON)
		put_camera_info(m->mlx, m->cam, m->f);
}
