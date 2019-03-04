/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:54:07 by edraugr-          #+#    #+#             */
/*   Updated: 2018/11/27 19:55:54 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		h;
	int		n;

	h = 0;
	n = 0;
	if (!haystack[0] && needle[0])
		return (NULL);
	if (!haystack[0] && !needle[0])
		return ((char *)haystack);
	while (haystack[h])
	{
		while (needle[n] && haystack[h + n])
			if (needle[n] == haystack[h + n])
				n++;
			else
				break ;
		if (!needle[n])
			return ((char *)(haystack + h));
		n = 0;
		h++;
	}
	return (NULL);
}
