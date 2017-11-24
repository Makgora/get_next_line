/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:46:26 by tparand           #+#    #+#             */
/*   Updated: 2017/11/23 19:16:08 by tparand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*p_big;
	const char	*p_little;
	size_t		len_b;

	if (*little == '\0')
		return ((char *)big);
	while (len > 0 && *big != '\0')
	{
		p_big = big;
		p_little = little;
		len_b = len--;
		while (len_b > 0 && *p_big != '\0' && *p_little == *p_big)
		{
			p_little++;
			p_big++;
			len_b--;
		}
		if (*p_little == '\0')
			return ((char *)big);
		big++;
	}
	return (NULL);
}
