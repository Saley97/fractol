/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:04:30 by edraugr-          #+#    #+#             */
/*   Updated: 2018/11/27 16:08:12 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	int			i;

	d = (char *)dst;
	s = (const char *)src;
	if (d == s)
		return ((void *)d);
	if (d < s)
	{
		i = -1;
		while ((size_t)++i < len)
			d[i] = s[i];
	}
	else
	{
		i = (int)len;
		while (--i >= 0)
			d[i] = s[i];
	}
	return ((void *)d);
}
