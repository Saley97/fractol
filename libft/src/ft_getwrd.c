/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwrd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:04:41 by edraugr-          #+#    #+#             */
/*   Updated: 2018/11/29 17:21:10 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_getwrd(const char *str, const char *dlms)
{
	int		len;
	int		i;
	char	*res;

	i = -1;
	if (!str || !(len = ft_getwrdlen(str, dlms)))
		return (NULL);
	if (!(res = (char *)malloc(len + 1)))
		return (NULL);
	while (++i < len)
		res[i] = str[i];
	res[i] = '\0';
	return (res);
}
