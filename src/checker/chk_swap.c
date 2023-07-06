/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:11:23 by erivero-          #+#    #+#             */
/*   Updated: 2023/07/06 11:28:50 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	swap(t_stack *stack)
{
	int	c;

	c = stack->numbers[stack->top - 1];
	stack->numbers[stack->top - 1] = stack->numbers[stack->top];
	stack->numbers[stack->top] = c;
}

void	chk_sa(t_stack *stack_a)
{
	swap(stack_a);
}

void	chk_sb(t_stack *stack_b)
{
	swap(stack_b);
}

void	chk_ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}