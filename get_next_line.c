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
	free(str);
	return (new_str);
}

int		get_next_line(const int fd, char **line)
{
	static char	buffer[BUFF_SIZE];
	int		n_pos;
	size_t		line_len;

	n_pos = BUFF_SIZE;
	while (n_pos == BUFF_SIZE)
	{
		if (read(fd, buffer, BUFF_SIZE) < 0)
			return (-1);
		buffer[BUFF_SIZE] = '\0';
		n_pos = ft_strclen(buffer, '\n');
		*line = ft_realloc(*line, ft_strlen(*line), n_pos);
		ft_strncat(*line, buffer, n_pos);
		line_len += n_pos;
	}
	printf("%zu\n", line_len);	
	return (*line[line_len - 1] == EOF ? 0 : 1);
}
