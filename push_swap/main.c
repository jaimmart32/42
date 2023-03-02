/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart32 <jaimmart32@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:11:00 by jaimmart          #+#    #+#             */
/*   Updated: 2023/03/01 16:25:34 by jaimmart32       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Initialize the stack with the input arguments.*/
static void	init_stack(t_list **stack, int argc, char **argv)
{
	t_list	*new_node;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new_node = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new_node);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		ft_free(args);
}

/*Sort depending on the size of the stack to order for efficiency.*/
static void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (-1);
	check_args(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	init_stack(stack_a, argc, argv);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

