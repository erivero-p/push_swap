/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:14:07 by erivero-          #+#    #+#             */
/*   Updated: 2023/07/06 11:33:19 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rotate(t_stack *stack)
{
	int	i;
	int	aux;

	aux = stack->numbers[stack->top];
	i = stack->top;
	while (i > 0)
	{
		stack->numbers[i] = stack->numbers[i - 1];
		i--;
	}
	stack->numbers[0] = aux;
}

void	chk_ra(t_stack *stack_a)
{
	rotate(stack_a);
}

void	chk_rb(t_stack *stack_b)
{
	rotate(stack_b);
}

void	chk_rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

