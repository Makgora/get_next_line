/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:42:41 by tparand           #+#    #+#             */
/*   Updated: 2017/11/10 17:09:36 by tparand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	char		*p_str1;
	const char	*p_str2;

	p_str1 = (char *)str1;
	p_str2 = (const char *)str2;
	while (n-- > 0)
		*p_str1++ = *p_str2++;
	return (str1);
}
