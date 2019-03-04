/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:33:26 by edraugr-          #+#    #+#             */
/*   Updated: 2018/11/30 20:15:02 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	dell(void *cont, size_t cs)
{
	ft_memdel(&cont);
	cs = 0;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*tmp;
	void	(*fd)(void *, size_t);

	fd = dell;
	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	if (!tmp)
		return (NULL);
	res = tmp;
	lst = lst->next;
	while (lst)
	{
		tmp->next = f(lst);
		tmp = tmp->next;
		if (!tmp)
		{
			ft_lstdel(&res, fd);
			return (res);
		}
		lst = lst->next;
	}
	return (res);
}
