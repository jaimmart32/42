/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart <jaimmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:33:44 by jaimmart          #+#    #+#             */
/*   Updated: 2022/09/26 17:35:57 by jaimmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_nodo;

	if (!lst)
		return (NULL);
	while (lst)
	{
		if (!lst->next)
			last_nodo = lst;
		lst = lst->next;
	}
	return (last_nodo);
}
/*lst = lst->next     incrementar en 1 el nodo de la lista "=" (i++;)*/
