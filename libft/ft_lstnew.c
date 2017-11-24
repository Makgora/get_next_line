/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:42:24 by tparand           #+#    #+#             */
/*   Updated: 2017/11/10 16:49:10 by tparand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_lst;

	new_lst = NULL;
	new_lst = (t_list *)malloc(sizeof(t_list));
	if (!new_lst)
		return (NULL);
	if (content == NULL)
	{
		new_lst->content = NULL;
		new_lst->content_size = 0;
	}
	else
	{
		new_lst->content = malloc(content_size);
		if (!new_lst->content)
			return (NULL);
		new_lst->content = ft_memcpy(new_lst->content, content, content_size);
		new_lst->content_size = content_size;
	}
	new_lst->next = NULL;
	return (new_lst);
}
