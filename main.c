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
#include <stdio.h>

int		open_file(int argc, char **argv)
{
	int		fd;

	fd = -1;
	if (argc == 1)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
		fd = open(argv[1], O_RDONLY);
	return (fd);
}

void	print_file(int fd)
{
	char	buffer[10];
	int		bytes_readed;
	int		nbytes;

	nbytes = sizeof(buffer);
	while ((bytes_readed = read(fd, buffer, nbytes)) != 0)
		write(1, buffer, bytes_readed);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	**line;

	line = (char **)malloc(sizeof(char));
	fd = open_file(argc, argv);
	if (fd < 0)
		return (0);
	//print_file(fd);
	get_next_line(fd, line);
	printf("%s\n", *line);
	close(fd);
	return (0);
}
