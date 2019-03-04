/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:01:21 by edraugr-          #+#    #+#             */
/*   Updated: 2018/11/27 19:46:31 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && i < n)
	{
		if (!s1[i])
			return (0);
		i++;
	}
	if (i == n)
		i = n - 1;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
