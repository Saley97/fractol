/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrdscount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:23:19 by edraugr-          #+#    #+#             */
/*   Updated: 2018/11/29 21:17:01 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wrdscount(const char *str, const char *dlms)
{
	int	res;
	int	i;
	int	dlm;

	res = 0;
	i = 0;
	dlm = ft_dlmscount(str, dlms);
	while (dlm >= 0)
	{
		res++;
		i += dlm;
		while (!ft_checkdlms(str[i], dlms) && str[i])
			i++;
		if (!str[i])
			return (res);
		dlm = ft_dlmscount(str + i, dlms);
	}
	return (res);
}
