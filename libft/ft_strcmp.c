/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:44:59 by tparand           #+#    #+#             */
/*   Updated: 2017/11/13 21:37:35 by tparand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned const char	*p_s1;
	unsigned const char	*p_s2;

	p_s1 = (unsigned const char *)s1;
	p_s2 = (unsigned const char *)s2;
	while (*p_s1 != '\0' && *p_s1 == *p_s2)
	{
		p_s1++;
		p_s2++;
	}
	return (*p_s1 - *p_s2);
}
