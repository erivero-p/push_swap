/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:58:38 by erivero-          #+#    #+#             */
/*   Updated: 2023/07/04 19:10:29 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_max_position(t_stack *stack_b)
{
	int	i;
	int	biggest_pos;
	int	*n;

	biggest_pos = stack_b->top;
	i = biggest_pos - 1;
	n = stack_b->numbers;
	while (i >= 0)
	{
		if (n[i] > n[biggest_pos])
			biggest_pos = i;
		i--;
	}
	return (biggest_pos);
}

void	big_sorter(t_stack *stack_a, t_stack *stack_b, int stack_count)
{
	int	biggest_pos;

	push_chunks(stack_a, stack_b, stack_count);
	while (stack_b->top >= 0)
	{
		biggest_pos = find_max_position(stack_b);
//		ft_printf("biggest num: %i\n", stack_b->numbers[biggest_pos]);
		if (biggest_pos >= stack_b->top / 2)
		{ //< porque quiero llegar a top pero no cambiar top
			while (biggest_pos++ < stack_b->top)
				rb(stack_b);
		}
		else
		{ // >= porque quiero llegar a 0 y cambiarlo
			while (biggest_pos-- >= 0)
				rrb(stack_b);
		}
//		ft_printf("el número a pushear es: %i\n", stack_a->numbers[stack_a->top]);
		pa(stack_a, stack_b);
	}
}
