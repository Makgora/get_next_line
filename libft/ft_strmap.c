/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:45:33 by tparand           #+#    #+#             */
/*   Updated: 2017/11/13 22:12:15 by tparand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	char	*p_new;

	if (s == NULL)
		return (NULL);
	new = ft_strnew(ft_strlen(s));
	if (!new)
		return (NULL);
	p_new = new;
	while (*s != '\0')
		*new++ = f(*s++);
	return (p_new);
}
