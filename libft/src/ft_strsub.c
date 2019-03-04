/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:48:29 by edraugr-          #+#    #+#             */
/*   Updated: 2018/11/30 19:24:42 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*res;

	if (!s || ft_strlen(s) < len)
		return (NULL);
	slen = (size_t)ft_strlen(s);
	if (start >= slen)
		return (NULL);
	len = (len >= slen - start) ? slen - start : len;
	if (!(res = (char *)malloc(len + 1)))
		return (NULL);
	slen = 0;
	while (slen < len && s[slen + start])
	{
		res[slen] = s[slen + start];
		slen++;
	}
	res[slen] = '\0';
	return (res);
}
