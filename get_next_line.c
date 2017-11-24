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

int		get_next_line(const int fd, char **line)
{
	char	buffer[BUFF_SIZE];
	int		bytes_readed;

	bytes_readed = read(fd, buffer, BUFF_SIZE);
	while ()
	{
		
	}
}

//Je read mon buffer;
//Strclen pour savoir si il y a un \n
//Je realloc avec strclen
//Je concatene line avc buffer;

