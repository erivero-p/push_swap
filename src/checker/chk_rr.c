/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:14:28 by erivero-          #+#    #+#             */
/*   Updated: 2023/07/10 16:25:37 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	int	i;
	int	aux;

	aux = stack->numbers[0];
	i = 0;
	while (i < stack->top)
	{
		stack->numbers[i] = stack->numbers[i + 1];
		i++;
	}
	stack->numbers[stack->top] = aux;
}

void	chk_rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
}

void	chk_rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
}

void	chk_rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
