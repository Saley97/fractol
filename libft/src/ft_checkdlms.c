/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdlms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:47:04 by edraugr-          #+#    #+#             */
/*   Updated: 2018/11/29 16:36:50 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkdlms(char c, const char *dlms)
{
	int	i;

	i = -1;
	while (dlms[++i])
		if (ft_checkdlm(c, dlms[i]))
			return (1);
	return (0);
}
