/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 23:32:40 by edraugr-          #+#    #+#             */
/*   Updated: 2018/11/29 14:38:57 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dist, const void *src, int c, size_t n)
{
	unsigned char	*temp_s;
	unsigned char	*temp_d;

	temp_d = (unsigned char *)dist;
	temp_s = (unsigned char *)src;
	while (n--)
	{
		*temp_d = *temp_s;
		if (*temp_d == (unsigned char)c)
			return (++temp_d);
		else
		{
			temp_d++;
			temp_s++;
		}
	}
	return (NULL);
}
