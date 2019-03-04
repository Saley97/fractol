/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 23:20:18 by edraugr-          #+#    #+#             */
/*   Updated: 2018/11/30 17:54:18 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*nxt;
	t_list	*d;

	if (!alst || !*alst)
		return ;
	nxt = *alst;
	d = NULL;
	while (nxt)
	{
		d = nxt;
		nxt = nxt->next;
		ft_lstdelone(&d, del);
	}
	*alst = NULL;
}
