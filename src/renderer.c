/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 19:07:07 by edraugr-          #+#    #+#             */
/*   Updated: 2019/03/04 09:19:46 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		get_coef(t_vec3 *p, const t_fconf *f)
{
	t_vec3	*z;
	int		i;
	double	r;
	double	r2;

	z = vec3_copy(p);
	if (f->demen == CAM_2D)
		p->z = 0.0;
	r2 = p->x * p->x + p->y * p->y + p->z * p->z;
	r = sqrt(r2);
	set_m(p, f, r2);
	i = -1;
	while (++i < FRAC_DDP - 1)
	{
		precalc_m(z, f, r, r2);
		calc_m(z, f);
		vec3_set(z, z->x + p->x, z->y + p->y, z->z + p->z);
		if (z->x * z->x + z->y * z->y + z->z * z->z > 4)
			break ;
	}
	free(z);
	return (i);
}

void	*fill_image(void *tr)
{
	t_vec2		*s_p;
	t_vec3		*w_p;
	t_thread	*t;
	int			i;
	int			j;

	t = (t_thread *)tr;
	i = SCREEN_Y / THREADS * t->id - 1;
	s_p = vec2_init();
	w_p = vec3_init();
	while (++i < (SCREEN_Y / THREADS * (t->id + 1)))
	{
		j = -1;
		while (++j < SCREEN_X)
		{
			vec2_set(s_p, j, i);
			calc_world_from_screen(s_p, w_p, t->m_data->cam);
			image_set_pixel(t->m_data->mlx->image,
				j - SCREEN_X / 2, i - SCREEN_Y / 2,
				choose_color(t->m_data->f, get_coef(w_p, t->m_data->f)));
		}
	}
	free(s_p);
	free(w_p);
	return (NULL);
}

void	thread_img_filler(t_mouse *m)
{
	int	i;

	i = -1;
	while (++i < THREADS)
	{
		m->t->arg[i].id = i;
		m->t->arg[i].m_data = m;
		pthread_create(m->t->threads + i, NULL,
			fill_image, &(m->t->arg[i]));
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(m->t->threads[i], NULL);
}
