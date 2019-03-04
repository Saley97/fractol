/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 01:58:27 by edraugr-          #+#    #+#             */
/*   Updated: 2019/03/04 02:04:50 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

void	image_free(t_image **img)
{
	if (!img || !*img)
		return ;
	ft_memdel((void **)&((*img)->image));
	ft_memdel((void **)&((*img)->ptr));
	ft_memdel((void **)img);
	*img = NULL;
}
