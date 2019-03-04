/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 20:04:23 by edraugr-          #+#    #+#             */
/*   Updated: 2019/03/04 09:20:01 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static t_cl_list	*read_cl(int fd)
{
	int			cl;
	char		*cl_ch;
	char		*shit;
	t_cl_list	*res;

	cl_ch = NULL;
	if (get_next_line(fd, &cl_ch) != 1
		|| !(res = (t_cl_list *)malloc(sizeof(t_cl_list))))
	{
		if (cl_ch != NULL)
			free(cl_ch);
		return (NULL);
	}
	cl = (int)strtol(cl_ch, &shit, 16);
	res->color = cl;
	res->n_cl_list = NULL;
	if (cl_ch != NULL)
		free(cl_ch);
	return (res);
}

t_cl_list			*set_colors(const char *file)
{
	int			fd;
	t_cl_list	*res;
	t_cl_list	*tmp;

	res = NULL;
	fd = open(file, O_RDONLY);
	tmp = read_cl(fd);
	while (tmp != NULL)
	{
		tmp->n_cl_list = res;
		res = tmp;
		tmp = read_cl(fd);
	}
	tmp = res;
	while (tmp->n_cl_list != NULL)
		tmp = tmp->n_cl_list;
	tmp->n_cl_list = res;
	close(fd);
	return (res);
}
