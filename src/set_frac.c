/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_frac.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 22:23:27 by edraugr-          #+#    #+#             */
/*   Updated: 2019/03/04 08:41:09 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void inline	set_coef(t_fconf *f)
{
	f->coef[0][0] = 1.0;
	f->coef[0][1] = 0.0;
	f->coef[0][2] = 0.0;
	f->coef[1][0] = 0.0;
	f->coef[1][1] = 1.0;
	f->coef[1][2] = 0.0;
	f->coef[2][0] = 0.0;
	f->coef[2][1] = 0.0;
	f->coef[2][2] = 1.0;
}

static int			get_flag(const char *name)
{
	if (!ft_strcmp(name, "MANDEL"))
		return (MANDEL_MODE);
	if (!ft_strcmp(name, "JULY"))
		return (JUL_MODE);
	return (SHIP_MODE);
}

void				set_frac(t_fconf *f, char *name)
{
	int	flag;

	flag = get_flag(name);
	f->type = flag;
	f->demen = CAM_2D;
	f->calc_m = CALC_M_2;
	f->set_m = SET_M_STD;
	f->precalc_m = PRECALC_M_STD;
	f->m_x = 1.0;
	f->m_y = 1.0;
	f->lerp_m = LERP_M_OFF;
	f->play_station_m = PS_M_OFF;
	f->play_station_n = 2;
	f->info_m = INFO_M_ON;
	if (flag == JUL_MODE)
		f->jul_change_m = JUL_CH_M_ON;
	else
		f->jul_change_m = JUL_CH_M_OFF;
	f->cl_list = set_colors(CL_FILE_NAME);
	f->cl_num = FRAC_DDP - 1;
	fill_pallet(f);
	f->cl_num = 3;
	if (flag == SHIP_MODE)
		f->precalc_m = PRECALC_M_ABS;
	set_coef(f);
}
