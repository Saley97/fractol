/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:23:39 by edraugr-          #+#    #+#             */
/*   Updated: 2018/11/28 21:28:52 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*res;

	i = -1;
	if (!s || !f || !(res = (char *)malloc(ft_strlen(s) + 1)))
		return (NULL);
	while (s[++i])
		res[i] = f(s[i]);
	res[i] = '\0';
	return (res);
}
