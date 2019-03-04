/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwrdlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:57:36 by edraugr-          #+#    #+#             */
/*   Updated: 2018/11/29 20:52:49 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getwrdlen(const char *str, const char *dlms)
{
	int	res;

	res = 0;
	while (str[res] && !ft_checkdlms(str[res], dlms))
		res++;
	return (res);
}
