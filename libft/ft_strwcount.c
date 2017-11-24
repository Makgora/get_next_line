/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:46:44 by tparand           #+#    #+#             */
/*   Updated: 2017/11/10 16:50:51 by tparand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strwcount(char const *s, char c)
{
	int	new_word;
	int	nb_words;

	nb_words = 0;
	new_word = 1;
	while (*s != '\0')
	{
		if (*s != c)
		{
			if (new_word == 1)
			{
				new_word = 0;
				nb_words++;
			}
		}
		else
		{
			if (new_word == 0)
				new_word = 1;
		}
		s++;
	}
	return (nb_words);
}
