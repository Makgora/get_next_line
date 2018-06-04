#include "get_next_line.h"

void		print_buff(t_buff **s_buff)
{
	printf("\t\t\tBuff:\n");
	printf("\t\t\t\tContent:'%s'\n", (*s_buff)->content);
	printf("\t\t\t\tLen:'%d'\n", (*s_buff)->len);
	printf("\t\t\t\tIdx:'%d'\n", (*s_buff)->idx);
	printf("\t\t\t\tIs_last:'%d'\n", (*s_buff)->is_last);
	printf("\t\t\t\tIs_flushed:'%d'\n", (*s_buff)->is_flushed);
}

void		print_line(t_line **s_line)
{
	printf("\t\t\tLine:\n");
	printf("\t\t\t\tContent:'%s'\n", (*s_line)->content);
	printf("\t\t\t\tLen:'%d'\n", (*s_line)->len);
	printf("\t\t\t\tIs_ended:'%d'\n", (*s_line)->is_ended);
}

int		init(t_buff **s_buff, t_line **s_line)
{
	printf("\t\t[s_line is inited]\n");
	*s_line = (t_line *)malloc(sizeof(t_line));
	if(*s_line == NULL)
		return (-1);
	(*s_line)->content = ft_strnew(0);
	(*s_line)->len = 0;
	(*s_line)->is_ended = 0;

	if(*s_buff == NULL)
	{
		printf("\t\t[s_buff is inited]\n");
		*s_buff = (t_buff *)malloc(sizeof(t_buff));
		if(*s_buff == NULL)
			return (-1);
		(*s_buff)->content[BUFF_SIZE - 1] = '\0';
		(*s_buff)->len = 0;
		(*s_buff)->idx = 0;
		(*s_buff)->is_last = 0;
		(*s_buff)->is_flushed = 1;
	}
	print_buff(s_buff);
	print_line(s_line);
	return (0);
}

int		fill_buff(const int fd, t_buff **s_buff)
{
	if((*s_buff)->is_flushed == 1)
	{
		print_buff(s_buff);
		(*s_buff)->len = read(fd, (*s_buff)->content, BUFF_SIZE - 1);
		printf("\t\t\t[Lecture de '%d' bytes]\n", (*s_buff)->len);
		if((*s_buff)->len == -1)
			return (-1);
		if ((*s_buff)->len < BUFF_SIZE - 1)
		{
			printf("\t\t\t[Buff_is_last = 1]\n");
			(*s_buff)->is_last = 1;
		}
		(*s_buff)->idx = 0;
		(*s_buff)->is_flushed = 0;
	}
	print_buff(s_buff);
	return (0);

}

int		flush_buff(t_buff **s_buff, t_line **s_line)
{
	int	n_idx;
	char	*tmp;

	print_line(s_line);
	n_idx = ft_strclen(&((*s_buff)->content)[(*s_buff)->idx], '\n');
	tmp = ft_strndup(&((*s_buff)->content)[(*s_buff)->idx], n_idx);
	if (tmp == NULL)
		return (-1);
	printf("\t\t\t----------\n");
	printf("\t\t\tTmp: '%s'\n", tmp);
	printf("\t\t\tLine =  '%s' + '%s'\n", (*s_line)->content, tmp);
	printf("\t\t\t----------\n");
	(*s_line)->content = ft_strjoin((*s_line)->content, tmp);
	if ((*s_line)->content == NULL)
		return (-1);
	free(tmp);
	(*s_line)->len += n_idx;
	(*s_buff)->idx += n_idx;
	if ((*s_buff)->idx >= (*s_buff)->len)
	{
		printf("\t\t\t[Buff_is_flushed = 1]\n");
		(*s_buff)->is_flushed = 1;
	}	
	print_line(s_line);
	return (0);
}

int		fill_line(const int fd, t_buff **s_buff, t_line **s_line)
{
	while((*s_line)->is_ended == 0)
	{
		printf("\n\t\t[Fill buff]\n");
		if (fill_buff(fd, s_buff) == -1)
			return (-1);
		printf("\n\t\t[Flush buff]\n");
		if (flush_buff(s_buff, s_line) == -1)
			return (-1);
		printf("\n\t\t[Test line]\n");
		if((*s_line)->content[(*s_line)->len - 1] == '\n')
		{
			printf("\n\t\t[Line ended]\n");
			(*s_line)->content[(*s_line)->len - 1] = '\0';
			(*s_line)->len--;
			(*s_line)->is_ended = 1;
		}
	}
	if ((*s_buff)->is_flushed == 1 && (*s_buff)->is_last == 1)
		return (1);
	else
		return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_buff 	*s_buff;
	t_line		*s_line;
	int		code;

	printf("\t[Initialisation]\n");
	if (init(&s_buff, &s_line) == -1)
		return (-1);
	printf("\t[We start]\n");
	code = fill_line(fd, &s_buff, &s_line);
	printf("\t[We end]\n");
	printf("\t[My line affected to line]\n");
	*line = s_line->content;
	return (code);
}

//TODO GERER LE CAS OU LE FICHIER SE TERMINE SANS \n
