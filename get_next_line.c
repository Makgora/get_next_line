#include "get_next_line.h"


void		init(t_buff **buff, char **line)
{
	if(*line == NULL)
		*line = ft_strnew(0);
	if(*buff == NULL)
	{
		*buff = (t_buff *)malloc(sizeof(t_buff));
		(*buff)->idx = 0;
	}
}

void		fill_buff(const int fd, t_buff **buff)
{
printf("buffer: '%s'\n", (&(*buff)->content)[(*buff)->idx]);
printf("idx: '%d'\n", (*buff)->idx);
	read(fd, (*buff)->content, BUFF_SIZE - 1);
	(*buff)->content[BUFF_SIZE - 1] = '\0';
	(*buff)->idx = 0;
printf("buffer: '%s'\n", (&(*buff)->content)[(*buff)->idx]);
printf("idx: '%d'\n", (*buff)->idx);
}

void		flush_buff(t_buff **buff, char **line)
{
	int	next_line;

printf("buffer: '%s'\n", (&(*buff)->content)[(*buff)->idx]);
printf("idx: '%d'\n", (*buff)->idx);

	//TODO
	next_line = ft_strclen(&((*buff)->content)[(*buff)->idx], '\n');
	(*buff)->content[(*buff)->idx + next_line] = '\0';
	*line = ft_strjoin(*line, &((*buff)->content)[(*buff)->idx]);
	(*buff)->idx += next_line;
	//TODO

printf("buffer: '%s'\n", (&(*buff)->content)[(*buff)->idx]);
printf("idx: '%d'\n", (*buff)->idx);
}

int		fill_line(char **line, t_buff **buff)
{
	int	line_len;

printf("line: '%s'\n", *line);
printf("Je flush buffer\n");
	flush_buff(buff, line);
printf("line: '%s'\n", *line);
	line_len = ft_strlen(*line);
printf("line_len: '%d'\n", line_len);
printf("line_last: '%c'\n", (*line)[line_len - 1]);
	if(line_len > 0 && (*line)[line_len - 1] == '\n')
		return (1);
	else
		return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_buff 	*buff;

	init(&buff, line);

printf("Je fill line\n");
	while(fill_line(line, &buff) == 0)
	{
sleep(1);
printf("Je fill buffer\n");
		fill_buff(fd, &buff);
printf("Je fill line\n");
	}
	if(ft_strlen(*line) > 0)
		(*line)[ft_strlen(*line) - 1] = '\0';
	return (0);
}
