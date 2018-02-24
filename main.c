/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:37:31 by tparand           #+#    #+#             */
/*   Updated: 2017/11/24 12:47:09 by tparand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int	fd;
	char	*line;

	line = ft_memalloc(0);
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (-1);

	int m = 0;
	while (get_next_line(fd, &line) == 1 && m++ < 15)
	{
		printf("-->%s\n", line);
		free(line);
	}
	if (argc == 2)
		close(fd);
	return (0);
}
