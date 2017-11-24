/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:46:38 by tparand           #+#    #+#             */
/*   Updated: 2017/11/13 20:51:19 by tparand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*p_needle;
	const char	*p_haystack;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		p_haystack = haystack;
		p_needle = needle;
		while (*p_haystack != '\0' && *p_needle == *p_haystack)
		{
			p_needle++;
			p_haystack++;
		}
		if (*p_needle == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
