/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:41:07 by tparand           #+#    #+#             */
/*   Updated: 2017/11/10 16:54:05 by tparand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	unsigned int	n;
	int				sign;

	sign = 1;
	n = 0;
	while (*nptr == ' ' || *nptr == '\t'
			|| *nptr == '\n' || *nptr == '\r'
			|| *nptr == '\v' || *nptr == '\f')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit((int)*nptr) == 1)
	{
		n = 10 * n + (*nptr - '0');
		nptr++;
	}
	return (n * sign);
}
