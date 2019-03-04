/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:10:25 by edraugr-          #+#    #+#             */
/*   Updated: 2018/11/26 22:19:10 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (char *)b;
	while (i < len)
	{
		res[i] = (char)c;
		i++;
	}
	return ((void *)res);
}
