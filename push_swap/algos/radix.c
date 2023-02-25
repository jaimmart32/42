/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimmart32 <jaimmart32@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:12:58 by jaimmart          #+#    #+#             */
/*   Updated: 2023/02/22 18:14:44 by jaimmart32       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/*La función get_max_bits() recorre la pila stack y encuentra el valor máximo 
dentro de ella (a través de la comparación del índice de cada elemento con el 
valor máximo actual) y luego determina el número de bits necesarios para 
representar el valor máximo en binario. Esto se logra mediante el desplazamiento
de bits(>>) hacia la derecha del valor máximo en un bucle hasta que el valor 
resultante se convierte en cero, lo que indica que se han desplazado todos los 
bits del valor original.

La función devuelve el número de veces 
que se realizó el desplazamiento, que es igual al número de bits necesarios 
para representar el valor máximo. */
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

/*El resultado de get_max_bits() se utiliza en la función radix_sort() para 
determinar el número de iteraciones necesarias para clasificar correctamente
los elementos de la pila.

radix_sort() simplifica los numeros del stack en un index de 0 a stack_size
los transforma a base 2(no hay 10 boxes hay 2 stacks), y despues aplica el 
algoritmo de ordenamiento radix sort MSD (ordenación por bits más 
significativos) Los elementos cuyo bit actual es 1 se dejan en stack_a, y 
los que tienen un 0 en el bit actual se mueven a stack_b. Esto se hace 
llamando a las funciones ra() y pb(), respectivamente.

Una vez que se ha recorrido toda la pila stack_a, se transfiere el 
contenido de stack_b de vuelta a stack_a en orden inverso, utilizando la 
función pa. Después de que se han completado todas las iteraciones del 
bucle, stack_a contendrá los elementos clasificados en orden ascendente.*/
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
