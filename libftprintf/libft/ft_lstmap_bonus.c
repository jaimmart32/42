/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:29:09 by jaimmart          #+#    #+#             */
/*   Updated: 2022/10/13 13:06:25 by jaimmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdlib.h>

t_list	*ft_lsapply(t_list *l, t_list *s, void *(*f)(void *), void (*d)(void *))
{
	if (l)
	{
		s = ft_lstnew(f(l->content));
		if (!s)
		{
			ft_lstclear(&s, d);
			return (NULL);
		}
		s->next = ft_lsapply(l->next, s->next, f, d);
	}
	return (s);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;

	new_list = NULL;
	new_list = ft_lsapply(lst, new_list, f, del);
	return (new_list);
}
