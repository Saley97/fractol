/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 22:09:20 by edraugr-          #+#    #+#             */
/*   Updated: 2018/11/29 22:46:38 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*cont;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->next = NULL;
	if (!content || !(cont = ft_memalloc(content_size)))
	{
		new->content = NULL;
		new->content_size = 0;
		return (new);
	}
	new->content = ft_memcpy(cont, content, content_size);
	new->content_size = content_size;
	return (new);
}
