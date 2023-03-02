/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart32 <jaimmart32@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:12:58 by jaimmart          #+#    #+#             */
/*   Updated: 2023/03/02 19:03:03 by jaimmart32       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/*The get_max_bits() function walks through the stack and finds the maximum 
value within it (through the comparison of the index of each element with the
current maximum value) and then determines the number of bits needed to
represent the maximum value in binary. This is accomplished by moving
of bits(>>) to the right of the maximum value in a loop until the value
resultant becomes zero, indicating that all the values ​​have been shifted.

The function returns the number of times
that the shift was performed, which is equal to the number of bits needed
to represent the maximum value.*/
static int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

/*The result of get_max_bits() is used in the radix_sort() function to
determine the number of iterations needed to classify correctly
the elements of the stack.

radix_sort() simplifies stack numbers at an index from 0 to stack_size
transforms them to base 2 (there are not 10 boxes, there are 2 stacks), 
and then applies the radix sort MSD sorting algorithm. Elements whose 
current bit is 1 are left in stack_a, and those with a 0 in the current 
bit are moved to stack_b. This is done calling the functions ra() and pb()
, respectively.

Once the entire stack_a has been traversed, the
contents of stack_b back to stack_a in reverse order, using the
pa() function. After all iterations of the
loop, stack_a will contain the items sorted in ascending order.

& bitwise operand compares the last bit with 1, if it is 1 and 1the output
will be 1 and the node will be rotated and remaining in stack_a, if its 0
and 1, the output will be 0 and the node will be pushed to stack_b.*/
void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *stack_a;
	size = ft_lstsize(head_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
