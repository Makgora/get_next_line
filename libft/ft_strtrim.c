/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:46:41 by tparand           #+#    #+#             */
/*   Updated: 2017/11/13 23:17:41 by tparand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	end;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	start = i;
	end = i;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
			i++;
		if (s[i] != '\0')
			end = ++i;
	}
	return (ft_strsub(s, start, end - start));
}
