/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:18:32 by edraugr-          #+#    #+#             */
/*   Updated: 2018/11/30 19:12:11 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (!size)
		return (ft_strlen(src));
	while (dst[++i] && i < size)
		;
	while (src[++j] && i < size - 1)
		dst[i++] = src[j];
	if (i < size)
		dst[i] = '\0';
	return ((size_t)(i + ft_strlen(src + j)));
}
