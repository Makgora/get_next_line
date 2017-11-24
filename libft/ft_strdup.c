/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:45:07 by tparand           #+#    #+#             */
/*   Updated: 2017/11/11 18:08:04 by tparand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	char	*new_s;

	s_len = ft_strlen(s);
	new_s = ft_strnew(s_len);
	if (!new_s)
		return (NULL);
	return (ft_memcpy(new_s, s, s_len));
}
