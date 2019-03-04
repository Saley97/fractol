/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 21:25:13 by edraugr-          #+#    #+#             */
/*   Updated: 2018/11/29 13:22:44 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	int		i;
	int		temp;
	char	*res;

	i = n >= 0 ? 2 : 3;
	temp = n;
	while ((temp = temp / (10 * (temp >= 0 ? 1 : -1))) > 0)
		i++;
	if (!(res = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	res[--i] = '\0';
	if (n < 0)
		res[0] = '-';
	while (n / (10 * (n >= 0 ? 1 : -1)) > 0)
	{
		res[--i] = n >= 0 ? (n % 10) + '0' : (n % 10) * -1 + '0';
		n /= 10;
	}
	res[--i] = n >= 0 ? (n % 10) + '0' : (n % 10) * -1 + '0';
	return (res);
}
