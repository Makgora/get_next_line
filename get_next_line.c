/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:25:06 by tparand           #+#    #+#             */
/*   Updated: 2017/11/24 15:58:16 by tparand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_realloc(char *str, size_t str_len, size_t len)
{
	char	*new_str;
	
	if (!str)
		return (NULL);
	new_str = ft_memalloc(str_len + len);
	if (!new_str)
		return (NULL);
	ft_strcpy(new_str, str);
	return (new_str);
}

int		get_next_line(const int fd, char **line)
{
	char	buffer[BUFF_SIZE];
	int	n_pos;

	read(fd, buffer, BUFF_SIZE);
	n_pos = ft_strclen(buffer, 'l');
	printf("n_pos: %d\n", n_pos);
	*line = ft_realloc(*line, ft_strlen(*line), n_pos);
	//printf("1n_pos: %d, line_len: %zu\n", n_pos, ft_strlen(*line));
	ft_strncat(*line, buffer, n_pos);
	return (0);
}
