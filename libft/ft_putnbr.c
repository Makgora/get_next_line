/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:43:06 by tparand           #+#    #+#             */
/*   Updated: 2017/11/21 13:45:02 by tparand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr_aux(long int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		putnbr_aux(n * -1);
	}
	else if (n > 0)
	{
		putnbr_aux(n / 10);
		ft_putchar(n % 10 + '0');
	}
}

void		ft_putnbr(int n)
{
	if (n == 0)
		ft_putchar('0');
	else
		putnbr_aux((long int)n);
}
