/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlmscount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:42:32 by edraugr-          #+#    #+#             */
/*   Updated: 2018/11/29 16:50:12 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dlmscount(const char *str, const char *dlms)
{
	int	res;

	res = 0;
	while (ft_checkdlms(str[res], dlms) && str[res])
		res++;
	if (!str[res])
		return (-1);
	return (res);
}
