/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:42:48 by tparand           #+#    #+#             */
/*   Updated: 2017/11/11 20:19:46 by tparand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*p_dest;
	unsigned const char *p_src;

	p_dest = (unsigned char *)dest;
	p_src = (unsigned const char *)src;
	if (p_src > p_dest)
	{
		while (n-- > 0)
			*p_dest++ = *p_src++;
	}
	else
	{
		p_dest += n - 1;
		p_src += n - 1;
		while (n-- > 0)
			*p_dest-- = *p_src--;
	}
	return (dest);
}
