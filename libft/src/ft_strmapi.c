/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:29:43 by edraugr-          #+#    #+#             */
/*   Updated: 2018/11/28 21:30:51 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	i = -1;
	if (!s || !f || !(res = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	while (s[++i])
		res[i] = f(i, s[i]);
	res[i] = '\0';
	return (res);
}
