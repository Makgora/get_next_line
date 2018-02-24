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

t_buff		*new_buff()
{
	t_buff	*t;

	t = (t_buff *)malloc(sizeof(t_buff));
	t->buff_len = 0;
	t->buff_idx = 0;
	t->line_len = 0;
	t->nxt_n = 0;
	return (t);
}

void 		fill_line(t_buff *b, char **line)
{
printf("\n[]Debut du remplissage[]\n");
	char	*tmp;
	size_t	tmp_len;

printf("Buff: [%s]\n", b->buff);
printf("Buff_idx: [%ld]\n", b->buff_idx);
printf("Buff[buff_idx]: [%s]\n", &(b->buff)[b->buff_idx]);
	b->nxt_n = ft_strclen(&(b->buff)[b->buff_idx], '\n');
printf("On calcule la position du prochain n : \t[%ld]\n", b->nxt_n);
	tmp_len = b->nxt_n;
printf("On calcule la taille de tmp : \t\t[%ld]\n", tmp_len);
printf("On realloc line de taille %ld + %ld\n", b->line_len, tmp_len);
	*line = ft_realloc(*line, b->line_len + tmp_len);
printf("Si line est NULL on alloc\n");
	if (!*line)
	{
		printf("On alloc une ligne vide\n");
		*line = ft_strnew(0);
	}
printf("Line : \t\t\t\t\t[%s]\n", *line);
	tmp = ft_strndup(&(b->buff)[b->buff_idx], tmp_len);
printf("On récupère la partie du buffer a vider:[%s]\n", tmp);
	ft_strncat(*line, tmp, tmp_len);
printf("On concat line et tmp : \t\t[%s]\n", *line);
	b->line_len += tmp_len;
printf("On renseigne la taille de line : \t[%ld]\n", b->line_len);
	b->buff_idx += b->nxt_n;
printf("On deplace le curseur du buff : \t[%ld]\n", b->buff_idx);
	free(tmp);
}

void		print_var(char *line, t_buff *b)
{
	printf("\n    - Statut -     \n");
	printf("Line: [%s]\n", line);
	printf("Line_len: [%ld]\n", b->line_len);
	printf("Buff: [%s]\n", b->buff);
	printf("Buff_len: [%ld]\n", b->buff_len);
	printf("Buff_idx: [%ld]\n", b->buff_idx);
	printf("Nxt_n: [%ld]\n", b->nxt_n);
}

int		get_next_line(const int fd, char **line)
{
printf("\n - Debut de la fonction gnl - \n\n");
	static t_buff	*b;
	
printf("On regarde si la struct b existe ?\n");
	if (!b)
	{
		b = new_buff();
printf(" -> Elle n'existe pas on la cree\n");
	}

	b->line_len = 0;
	*line = ft_strnew(0);
printf("On regarde si le buffer est plein ?\n");
	if (b->buff_idx < b->buff_len)
	{
printf(" -> Il est plein on remplit la line\n");
		fill_line(b, line);
	}

printf("On regarde si la line termine par |n ?\n");
int k = 0;
	while (ft_strchr(*line, '\n') == 0 && k++ < 10)
	{
printf(" -> Non !\n");
		b->buff_len = read(fd, b->buff, BUFF_SIZE - 1);
		b->buff_idx = 0;
printf("-->Buff_len: \t\t\t[%ld]\n", b->buff_len);
		b->buff[b->buff_len] = '\0';
printf("Buff: [%s]\n", b->buff);
printf("On vide le buffer dans la line\n");
		fill_line(b, line);
printf("On regarde si la line termine par |n ?\n");
printf("Line: [%s]\n", *line);	
	}
//Need to cut last |n
printf("Line: [%s]\n", *line);
	return (1);
}
