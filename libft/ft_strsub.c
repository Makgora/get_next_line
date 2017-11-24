/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:46:40 by tparand           #+#    #+#             */
/*   Updated: 2017/11/13 23:33:13 by tparand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;

	if (s == NULL)
		return (NULL);
	new = ft_strnew(len);
	if (!new)
		return (NULL);
	new = ft_strncpy(new, &s[start], len);
	return (new);
}
