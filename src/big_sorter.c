/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:58:38 by erivero-          #+#    #+#             */
/*   Updated: 2023/06/30 17:47:07 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int find_max_position (t_stack *stack_b)
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
	ft_printf("biggest num: %i\n", n[biggest_pos]);
	return (biggest_pos);
}

void    big_sorter(t_stack *stack_a, t_stack *stack_b)
{
	int biggest_pos;
	
	if (stack_b->top >= 0)
	{
		biggest_pos = find_max_position(stack_b);
		if (biggest_pos >= stack_a->top / 2)
		{ //< porque quiero llegar a top pero no cambiar top
			while (biggest_pos++ < stack_a->top)
				rb(stack_a);
		}
		else
		{ // >= porque quiero llegar a 0 y cambiarlo
			while (biggest_pos-- >= 0)
				rrb(stack_a);
		}
		// ft_printf("el número a pushear es: %i\n", stack_a->numbers[stack_a->top]);
		pa(stack_a, stack_b);
	}
}
