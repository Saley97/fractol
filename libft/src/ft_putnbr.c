/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 21:10:50 by edraugr-          #+#    #+#             */
/*   Updated: 2018/11/30 19:30:41 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int	sign;

	sign = 1;
	if (n < 0)
	{
		ft_putchar('-');
		sign = -1;
	}
	if (n / 10 == 0)
	{
		ft_putchar(n * sign + '0');
		return ;
	}
	ft_putnbr((n / 10) * sign);
	ft_putchar((n % 10) * sign + '0');
}
