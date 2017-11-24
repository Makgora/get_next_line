/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:46:07 by tparand           #+#    #+#             */
/*   Updated: 2017/11/11 20:17:22 by tparand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*p_dest;

	p_dest = dest;
	while (*p_dest != '\0')
		p_dest++;
	while (n > 0 && *src != '\0')
	{
		*p_dest++ = *src++;
		n--;
	}
	*p_dest = '\0';
	return (dest);
}
