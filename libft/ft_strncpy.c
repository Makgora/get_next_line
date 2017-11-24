/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:46:16 by tparand           #+#    #+#             */
/*   Updated: 2017/11/11 18:13:24 by tparand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*p_dest;

	p_dest = dest;
	while (n > 0 && *src != '\0')
	{
		*p_dest++ = *src++;
		n--;
	}
	while (n-- > 0)
		*p_dest++ = '\0';
	return (dest);
}
