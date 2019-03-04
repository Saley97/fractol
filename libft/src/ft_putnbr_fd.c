/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 21:10:50 by edraugr-          #+#    #+#             */
/*   Updated: 2018/11/30 19:31:02 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	sign;

	sign = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		sign = -1;
	}
	if (n / 10 == 0)
	{
		ft_putchar_fd(n * sign + '0', fd);
		return ;
	}
	ft_putnbr_fd((n / 10) * sign, fd);
	ft_putchar_fd((n % 10) * sign + '0', fd);
}
