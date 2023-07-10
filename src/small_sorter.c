/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:57:18 by erivero-          #+#    #+#             */
/*   Updated: 2023/07/10 16:24:43 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//friendly reminder de que tengo los números al revés

void	sort_three(t_stack *stack_a)
{
	int	*n;

	n = stack_a->numbers; //                         [2][1][0]
	if (n[2] > n[1] && n[2] < n[0] && n[1] < n[0]) // 2  1  3
		sa(stack_a);
	else if (n[2] > n[1] && n[2] > n[0] && n[1] < n[0])// 3  1  2
		ra(stack_a);
	else if (n[2] < n[1] && n[2] > n[0] && n[1] > n[0])//  2  3  1
		rra(stack_a);
	else if (n[2] < n[1] && n[2] < n[0] && n[1] > n[0])//  1  3  2
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (n[2] > n[1] && n[2] > n[0] && n[1] > n[0])//  3  2  1
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	sort_smallest(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	pos;
	int	*n;

	pos = stack_a->top;
	i = pos - 1;
	n = stack_a->numbers;
	while (i >= 0)
	{
		if (n[i] < n[pos])
			pos = i;
		i--;
	}
	if (pos >= stack_a->top / 2)
	{
		while (pos++ < stack_a->top)
			ra(stack_a);
	}
	else
	{
		while (pos-- >= 0)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}
/* while (pos++ < stack_a->top) < quiero llegar a top pero no cambiarlo
while (pos-- >= 0) >= quiero llegar a 0 y cambiarlo */

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	sort_smallest(stack_a, stack_b);
	sort_smallest(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_few(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
	{
		if (stack_a->numbers[1] > stack_a->numbers[0])
			sa(stack_a);
	}
	if (stack_a->size == 3)
		sort_three(stack_a);
	if (stack_a->size == 4)
	{
		sort_smallest(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
	}
	if (stack_a->size == 5)
		sort_five(stack_a, stack_b);
	if (stack_a->size > 5)
	{
		sort_smallest(stack_a, stack_b);
		sort_five(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}
