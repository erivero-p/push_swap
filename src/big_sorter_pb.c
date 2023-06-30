/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorter_pb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:14:43 by erivero-          #+#    #+#             */
/*   Updated: 2023/06/30 12:41:21 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	chunk_size(t_stack *stack_a)
{
	int	len;
	int	size;

	stack_a->max = stack_a->numbers[0];
	stack_a->start = stack_a->max;
	len = stack_a->top;
	while (len-- > 0)
	{
		if (stack_a->max < stack_a->numbers[len])
			stack_a->max = stack_a->numbers[len];
		if (stack_a->start > stack_a->numbers[len])
			stack_a->start = stacK_a->numbers[len];
	}
	size = stack_a->max - start + 1;
	return (size);
}

int	chunk_check(t_stack *stack_a, int start, int end)
{
	int	i;

	i = 0;
	while (i <= stack_a->top)
	{
		if (stack_a->numbers[i] >= start && stack_a->numbers[i] <= end)
			return (i + 1); // el costo de ponerlo en top
		i++;
	}
	return (0);
}

int	top_cost(t_stack *stack_a)
{
	int	len;

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

void	chunk_sort(t_stack *stack_a, int start, int end)
{
	int	cost;

	if (chunk_check(stack_a, start, end) < top_cost(stack_a))
	{
		cost = chunk_check(stack_a, start, end);
		while (cost-- > 0)
			rra(stack_a);
	}
	else
	{
		cost = top_cost(stack_a);
		while (cost-- > 0)
			ra(stack_a);
	}
}

void	big_sorter_pb(t_stack *stack_a, t_stack *stack_b)
{
	int	start;
	int	end;
	int	size;
	int	cost;

	start = stack_a->start;
	size = chunk_size(numbers) / 5; // tengo que arreglar esto
	end = start + size;
	while (end <= stack_a->max)
	{
		if (chunk_check(stack_a, start, end))
		{
			chunk_sort(stack_a);
			pb
		}
		start = end + 1;
		end += size;
	}
}
