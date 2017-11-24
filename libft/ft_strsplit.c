/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:46:35 by tparand           #+#    #+#             */
/*   Updated: 2017/11/14 16:45:05 by tparand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*get_next_word(const char *s, char c)
{
	while (*s != '\0' && *s == c)
		s++;
	return (s);
}

char		**ft_strsplit(char const *s, char c)
{
	int		nb_words;
	char	**words_arr;
	int		i;
	size_t	word_len;

	if (s == NULL)
		return (NULL);
	nb_words = ft_strwcount(s, c);
	words_arr = (char **)malloc(sizeof(char **) * (nb_words + 1));
	if (!words_arr)
		return (NULL);
	i = 0;
	while (i < nb_words)
	{
		s = get_next_word(s, c);
		word_len = ft_strclen(s, c);
		words_arr[i] = ft_strndup(s, word_len);
		s += word_len;
		i++;
	}
	words_arr[i] = NULL;
	return (words_arr);
}
