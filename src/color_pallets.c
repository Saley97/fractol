/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pallets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 22:53:05 by edraugr-          #+#    #+#             */
/*   Updated: 2019/03/04 08:52:02 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		fill_pallet(t_fconf *f)
{
	int	i;
	int	j;

	i = -1;
	while (++i < f->cl_num)
	{
		j = rand() % 100;
		while (--j > 0)
			f->cl_list = f->cl_list->n_cl_list;
		f->pallet[i] = f->cl_list->color;
	}
}

static int	get_cl_lerp_off(const t_fconf *f, const int itter)
{
	int	step;
	int	ind;

	step = FRAC_DDP / (f->cl_num);
	ind = itter / (step + 1);
	if (ind > FRAC_DDP - 1)
		ind = FRAC_DDP - 1;
	return (f->pallet[ind]);
}

static int	get_cl_lerp_on(const t_fconf *f, const int itter)
{
	int		step;
	int		i1;
	double	k;

	step = FRAC_DDP / (f->cl_num - 1);
	i1 = itter / (step + 1);
	if (itter % step != 0)
		k = (double)((double)(itter % step) / (double)step);
	else
		k = 0.0;
	return (color_lerp(f->pallet[i1], f->pallet[i1 + 1], k));
}

int			choose_color(const t_fconf *f, const int itter)
{
	if (f->lerp_m == LERP_M_OFF)
		return (get_cl_lerp_off(f, itter));
	else
		return (get_cl_lerp_on(f, itter));
}
