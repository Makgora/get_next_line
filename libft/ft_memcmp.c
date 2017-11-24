/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:42:38 by tparand           #+#    #+#             */
/*   Updated: 2017/11/11 18:05:24 by tparand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*p_s1;
	unsigned const char	*p_s2;

	p_s1 = (unsigned const char *)s1;
	p_s2 = (unsigned const char *)s2;
	while (n > 0 && *p_s1 == *p_s2)
	{
		p_s1++;
		p_s2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*p_s1 - *p_s2);
}
