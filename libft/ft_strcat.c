/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:43:24 by tparand           #+#    #+#             */
/*   Updated: 2017/11/11 20:09:32 by tparand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	*p_dest;

	p_dest = dest;
	while (*p_dest != '\0')
		p_dest++;
	ft_strcpy(p_dest, src);
	return (dest);
}
