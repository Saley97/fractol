/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:52:29 by edraugr-          #+#    #+#             */
/*   Updated: 2018/11/29 21:46:59 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**ft_freeost(char ***res, int cw)
{
	while (cw >= 0)
	{
		free(*res[cw]);
		cw--;
	}
	free(*res);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		cw;
	int		len;
	int		j;
	char	dlms[2];

	cw = -1;
	j = 0;
	dlms[0] = c;
	dlms[1] = '\0';
	if (!s)
		return (NULL);
	len = ft_wrdscount(s, dlms);
	if (!(res = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (++cw < len)
	{
		j += ft_dlmscount(s + j, dlms) > 0 ? ft_dlmscount(s + j, dlms) : 0;
		if (!(res[cw] = ft_getwrd(s + j, dlms)))
			return (ft_freeost(&res, cw));
		j += ft_getwrdlen(s + j, dlms);
	}
	res[cw] = NULL;
	return (res);
}
