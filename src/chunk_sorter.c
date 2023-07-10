/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:14:43 by erivero-          #+#    #+#             */
/*   Updated: 2023/07/10 16:17:49 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	chunk_size(t_stack *stack_a)
{
	int	len;
	int	size;
	int	max;

	max = stack_a->numbers[0];
	stack_a->start = max;
	len = stack_a->top;
	while (len > 0)
	{
		if (max < stack_a->numbers[len])
			max = stack_a->numbers[len];
		if (stack_a->start > stack_a->numbers[len])
			stack_a->start = stack_a->numbers[len];
		len--;
	}
	size = max - stack_a->start + 1;
	return (size);
}
/* Esta función busca a la vez el número más grande y el más pequeño del stack,
devuelve la diferencia entre ambos, que será el "total de posibilidades"
y guarda el más pequeño en la estructura, ya que lo necesitaré más adelante
para usarlo como start del primer chunk */

int	chunk_check(t_stack *stack_a, int start, int end)
{
	int	i;

	i = 0;
	while (i <= stack_a->top)
	{
		if (stack_a->numbers[i] >= start && stack_a->numbers[i] <= end)
			return (i + 1);
		i++;
	}
	return (0);
}
/* devuelve i + 1 porque, además de chequear que haya un número del chunk
en el stack_a, devuelve el coste de ponerlo en top con reverse_rotate
(para después pushearlo). Una vez llegue a 0, habría que hacer una rotación más 
para ponerlo en top */

int	top_cost(t_stack *stack_a, int start, int end)
{
	int	len;
	int	top_cost;

	len = stack_a->top;
	while (len >= 0)
	{
		if (stack_a->numbers[len] >= start && stack_a->numbers[len] <= end)
			break ;
		len--;
	}
	top_cost = stack_a->top - len;
	return (top_cost);
}
/* el coste de poner algo en top será la 
diferencia entre top y la posición del número*/

void	chunk_sort(t_stack *stack_a, int start, int end)
{
	int	cost;

	if (chunk_check(stack_a, start, end) < top_cost(stack_a, start, end))
	{
		cost = chunk_check(stack_a, start, end);
		while (cost-- > 0)
			rra(stack_a);
	}
	else
	{
		cost = top_cost(stack_a, start, end);
		while (cost-- > 0)
			ra(stack_a);
	}
}

void	push_chunks(t_stack *stack_a, t_stack *stack_b, int stack_count)
{
	int	start;
	int	end;
	int	size;

	start = stack_a->start;
	size = chunk_size(stack_a) / stack_count;
	end = start + size;
	while (stack_a->top >= 0)
	{
		if (chunk_check(stack_a, start, end))
		{
			chunk_sort(stack_a, start, end);
			pb(stack_a, stack_b);
		}
		else
		{
			start = end + 1;
			end = start + size;
		}
	}
}
