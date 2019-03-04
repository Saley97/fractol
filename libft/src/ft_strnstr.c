/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:55:07 by edraugr-          #+#    #+#             */
/*   Updated: 2018/11/27 14:23:24 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		h;
	int		n;

	h = 0;
	n = 0;
	if (!haystack[0] && needle[0])
		return (NULL);
	while (haystack[h] && (size_t)h < len)
	{
		while (needle[n] && haystack[h + n] && (size_t)(h + n) < len)
		{
			if (needle[n] == haystack[h + n])
				n++;
			else
				break ;
		}
		if (!needle[n])
			return ((char *)(haystack + h));
		n = 0;
		h++;
	}
	return (NULL);
}
