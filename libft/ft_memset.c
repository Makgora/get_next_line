/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:42:52 by tparand           #+#    #+#             */
/*   Updated: 2017/11/10 17:09:24 by tparand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*p_str;

	p_str = (char *)str;
	while (n > 0)
	{
		*p_str = (unsigned char)c;
		p_str++;
		n--;
	}
	return (str);
}
