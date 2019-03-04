/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 00:42:43 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/04 08:32:14 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	free_cl_lst(t_cl_list *lst)
{
	t_cl_list	*tmp;
	t_cl_list	*to_del;

	tmp = lst->n_cl_list;
	while (tmp != lst)
	{
		to_del = tmp;
		tmp = tmp->n_cl_list;
		ft_memdel((void**)&to_del);
	}
	ft_memdel((void**)&lst);
}

int			free_helper(t_mlx **mlx, t_cam **cam, t_mouse **mouse)
{
	if (mlx && *mlx)
		mlx_free_ll3d(mlx);
	if (cam && *cam)
	{
		ft_memdel((void **)&((*cam)->cam));
		ft_memdel((void **)&((*cam)->piv));
		ft_memdel((void **)cam);
	}
	if (mouse && *mouse)
	{
		ft_memdel((void **)&((*mouse)->t));
		free_cl_lst((*mouse)->f->cl_list);
		ft_memdel((void **)mouse);
	}
	return (0);
}
