#include "get_next_line.h"

void		print_buff(t_buff **s_buff)
{
	printf("\t\t\tBuff:\n");
	printf("\t\t\t\tContent:'%s'\n", (*s_buff)->content);
	printf("\t\t\t\tLen:'%d'\n", (*s_buff)->len);
	printf("\t\t\t\tIdx:'%d'\n", (*s_buff)->idx);
}

void		print_line(t_line **s_line)
{
	printf("\t\t\tLine:\n");
	printf("\t\t\t\tContent:'%s'\n", (*s_line)->content);
	printf("\t\t\t\tLen:'%d'\n", (*s_line)->len);
}

void		init(t_buff **s_buff, t_line **s_line)
{
	//printf("\t\t[s_line is inited]\n");
	*s_line = (t_line *)malloc(sizeof(t_line));
	(*s_line)->content = ft_strnew(0);
	(*s_line)->len = 0;
		
	if(*s_buff == NULL)
	{
		//printf("\t\t[s_buff is inited]\n");
		*s_buff = (t_buff *)malloc(sizeof(t_buff));
		(*s_buff)->content[BUFF_SIZE - 1] = '\0';
		(*s_buff)->len = 0;
		(*s_buff)->idx = 0;
	}
	//print_buff(s_buff);
	//print_line(s_line);
}

int		fill_buff(const int fd, t_buff **s_buff)
{
	//print_buff(s_buff);
	if((*s_buff)->idx == (*s_buff)->len)
	{
		(*s_buff)->len = read(fd, (*s_buff)->content, BUFF_SIZE - 1);
		//printf("\t\t\t[Lecture de '%d' bytes]\n", (*s_buff)->len);
		if((*s_buff)->len == 0)
			return (1);
		if((*s_buff)->len == -1)
			return (-1);
		(*s_buff)->idx = 0;
		//print_buff(s_buff);
	}
	return (0);
}

int		flush_buff(t_buff **s_buff, t_line **s_line)
{
	int	next_line;
	char	*tmp;

	//print_line(s_line);
	next_line = ft_strclen(&((*s_buff)->content)[(*s_buff)->idx], '\n');
	//printf("\t\t\t----------\n");
	//printf("\t\t\tIdx: %d\n", (*s_buff)->idx);
	//printf("\t\t\tIdx char: '%c'\n", (*s_buff)->content[(*s_buff)->idx]);
	//printf("\t\t\tBContent : '%s'\n", (*s_buff)->content);
	//printf("\t\t\tBContentIdx : '%s'\n", &((*s_buff)->content)[(*s_buff)->idx]);
	//printf("\t\t\tNext_line: %d\n", next_line);
	tmp = ft_strndup(&((*s_buff)->content)[(*s_buff)->idx], next_line);
	//printf("\t\t\tTmp: '%s'\n", tmp);
	//printf("\t\t\tLine =  '%s' + '%s'\n", (*s_line)->content, tmp);
	//printf("\t\t\t----------\n");
	(*s_line)->content = ft_strjoin((*s_line)->content, tmp);
	free(tmp);
	(*s_line)->len += next_line;
	(*s_buff)->idx += next_line;
	if((*s_line)->content[(*s_line)->len - 1] == '\n')
	{
		(*s_line)->content[(*s_line)->len - 1] = '\0';
		(*s_line)->len--;
		//print_line(s_line);
		return (1);
	}
	else
	{
		//print_line(s_line);
		return (0);
	}
}

int		fill_line(const int fd, t_buff **s_buff, t_line **s_line)
{
	int	code;

	code = 0;
	while(code == 0)
	{
		//printf("\n\t\t[Fill buffer]\n");
		code = fill_buff(fd, s_buff);
		if(code == -1)
		{
			//printf("== CODE ERR -1 ==\n");
			return (-1);
		}
		else if(code == 1)
		{
			//printf("== CODE EOF 1 ==\n");
			return (1);
		}
		else
		{
			//printf("\n\t\t[Flush buffer]\n");
			code = flush_buff(s_buff, s_line);
			//printf("\t\tCode: '%d'\n", code);
		}	
	}
	//printf("== CODE LINE 0 ==\n");
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_buff 	*s_buff;
	t_line		*s_line;
	int		code;

	//printf("\t[Initialisation]\n");
	init(&s_buff, &s_line);
	//printf("\t[We start]\n");
	code = fill_line(fd, &s_buff, &s_line);
	//printf("\t[My line affected to line]\n");
	*line = s_line->content;
	return (code);
}
