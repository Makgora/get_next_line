/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:42:21 by tparand           #+#    #+#             */
/*   Updated: 2017/11/24 11:48:43 by tparand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*p_new;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	p_new = new;
	if (!new)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
		p_new->next = f(lst);
		p_new = p_new->next;
	}
	p_new->next = f(lst);
	return (new);
}
