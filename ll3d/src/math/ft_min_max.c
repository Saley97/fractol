/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraugr- <edraugr-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 22:24:33 by edraugr-          #+#    #+#             */
/*   Updated: 2019/02/19 19:08:26 by edraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

double	ft_fmin(const double a, const double b)
{
	return (a > b ? b : a);
}

int		ft_min(const int a, const int b)
{
	return (a > b ? b : a);
}

double	ft_fmax(const double a, const double b)
{
	return (a < b ? b : a);
}

int		ft_max(const int a, const int b)
{
	return (a < b ? b : a);
}
