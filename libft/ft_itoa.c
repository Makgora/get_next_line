/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:41:48 by tparand           #+#    #+#             */
/*   Updated: 2017/11/21 12:47:08 by tparand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_length(long int *nb)
{
	size_t		size;
	long int	n;

	size = 0;
	n = *nb;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		*nb *= -1;
		n *= -1;
		size++;
	}
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char		*str;
	size_t		str_len;
	long int	nb;

	nb = (long int)n;
	str_len = get_length(&nb);
	str = ft_strnew(str_len);
	if (!str)
		return (NULL);
	*str = '0';
	if (n < 0)
		*str = '-';
	while (nb > 0)
	{
		str[str_len - 1] = nb % 10 + '0';
		nb /= 10;
		str_len--;
	}
	return (str);
}
