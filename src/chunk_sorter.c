/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:14:43 by erivero-          #+#    #+#             */
/*   Updated: 2023/06/30 17:54:59 by erivero-         ###   ########.fr       */
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
			stack_a->start = stack_a->numbers[len];
	}
	size = stack_a->max - stack_a->start + 1;
/* 	ft_printf("start: %i\n", stack_a->start);
	ft_printf("max: %i\n", stack_a->max);
	ft_printf("size: %i\n", size); */
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


void	push_chunks(t_stack *stack_a, t_stack *stack_b)
{
	int	start;
	int	end;
	int	size;

	start = stack_a->start;
	size = chunk_size(stack_a) / 5; // tengo que arreglar esto
	end = start + size;
	while (stack_b->top >= 0)
	{
		if(chunk_check(stack_a, start, end))
		{
			chunk_sort(stack_a, start, end);
//			ft_printf("el número a pushear es: %i\n", stack_a->numbers[stack_a->top]);
			pb(stack_a, stack_b);
		}
		else
		{
			start = end + 1;
			end = start + size;
		}
		ft_printf("CAMBIO DE CHUNK\nstart: %i\nend: %i\n", start, end);
	}
}
