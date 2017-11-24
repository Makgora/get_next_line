/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:46:29 by tparand           #+#    #+#             */
/*   Updated: 2017/11/13 19:59:08 by tparand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occ;

	last_occ = NULL;
	while (*s != '\0')
	{
		if (*s == c)
			last_occ = (char *)s;
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (last_occ);
}
