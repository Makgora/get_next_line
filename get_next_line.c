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

void		fill_line(char *line, char *buffer)
{
	size_t 	n_pos;

	n_pos = 0;
	while (s->buffer[n_pos] == '\n')
	{
		
	}
	n_pos = ft_strclen(&(s->buffer)[n_pos], '\n');
	
}

void		clean_buffer(t_line *s)
{
printf("Buffer: [%s]\n", s->buffer);
printf("On calcule la pos du 1er n: %ld\n", s->n_pos);
	while (s->buffer[s->n_pos] == '\n')
		s->n_pos++;
printf("On avance tant qu'il y a des n: %ld\n", s->n_pos);
	s->buffer_len = ft_strclen(&(s->buffer)[s->n_pos], '\n');
printf("On calcule la taille du buffer: %ld\n", s->buffer_len);
	s->line = ft_strnew(s->buffer_len);
	s->line_len = s->buffer_len;
printf("On calcule la taille de line: %ld\n", s->line_len);
	ft_strncpy(s->line, &(s->buffer)[s->n_pos], s->buffer_len);
printf("On remplit la Line: [%s]\n", s->line);
}

int		get_next_line(const int fd, char **line)
{
	static t_buffer	*b;

printf("\nNEW LINE\n");
	if (b.buffer_len > 0)
		fill_line(*line, &b);
	clean_buffer(&s);
	s.n_pos = BUFF_SIZE;
printf("s.line[s.line_len - 1] : [%c]\n", s.line[s.line_len - 1]);
	while (s.line[s.line_len - 1] != '\n')
	{
		s.buffer_len = read(s.fd, s.buffer, BUFF_SIZE);
printf("\nBuffer_len prend le nb lu: %ld\n", s.buffer_len);
		s.buffer[s.buffer_len] = '\0';
printf("Buffer: [%s]\n", s.buffer);
		s.n_pos = ft_strclen(s.buffer, '\n');
printf("On calcule le n: %ld\n", s.n_pos);
		s.line = ft_realloc(s.line, s.line_len + s.n_pos);
		ft_strncat(s.line, s.buffer, s.n_pos);
printf("On concat buffer dans line: [%s]\n", s.line);
		s.line_len += s.n_pos;
printf("On calcule la line_len: %ld\n", s.line_len);
	}
printf("Line: [%s]\n", s.line);
	*line = s.line;
//printf("Buffer: [%s]\n", s.buffer);
//printf("Line_len: %ld\n", s.line_len);
	return (s.line_len == 0 ? 0 : 1);
}
Si mon buffer est pas vide je fill ma line

Sinon je rempli mon buffer
Et je fill ma line
