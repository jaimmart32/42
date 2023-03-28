/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart32 <jaimmart32@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:45:43 by jaimmart          #+#    #+#             */
/*   Updated: 2023/03/28 21:02:17 by jaimmart32       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(0);
}

/*Takes a double pointer to a string and frees all the memory allocated for 
each string and then for the array itself.*/
void	ft_free(char **str)
{
    if (!str || !*str)
        return;
    
    int i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}


/*Takes a double pointer to a linked list and frees all the memory allocated 
for each node and then for the linked list itself.*/
void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}
