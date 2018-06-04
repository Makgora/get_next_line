/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:25:15 by tparand           #+#    #+#             */
/*   Updated: 2017/11/24 12:45:02 by tparand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_buff
{
	char	content[BUFF_SIZE];
	int	len;
	int	idx;
	int	is_last;
	int	is_flushed;
}		t_buff;

typedef struct	s_line
{
	char	*content;
	int	len;
	int	is_ended;
}		t_line;

int		get_next_line(const int fd, char **line);

#endif
