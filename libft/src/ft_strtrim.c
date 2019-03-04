/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:53:59 by edraugr-          #+#    #+#             */
/*   Updated: 2018/11/29 12:52:13 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		start;
	int		len;
	char	*res;

	start = 0;
	if (!s)
		return (res = ft_strdup(""));
	len = ft_strlen(s);
	if (!len)
		return (res = ft_strdup(s));
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	if (!s[start])
		return (res = ft_strdup(""));
	while (s[--len] == ' ' || s[len] == '\t' || s[len] == '\n')
		;
	len = len - start + 1;
	return (res = ft_strsub(s, (unsigned int)start, (size_t)len));
}
