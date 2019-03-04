/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:58:23 by edraugr-          #+#    #+#             */
/*   Updated: 2018/11/29 12:39:18 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dist, const void *src, size_t n)
{
	const unsigned char	*temp_s;
	unsigned char		*temp_d;
	size_t				i;

	i = 0;
	temp_d = (unsigned char *)dist;
	temp_s = (const unsigned char *)src;
	while (i < n)
	{
		temp_d[i] = temp_s[i];
		i++;
	}
	return ((void *)temp_d);
}
