/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:43:09 by tparand           #+#    #+#             */
/*   Updated: 2017/11/21 13:45:53 by tparand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr_fd_aux(long int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		putnbr_fd_aux(n * -1, fd);
	}
	else if (n > 0)
	{
		putnbr_fd_aux(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
		putnbr_fd_aux((long int)n, fd);
}
