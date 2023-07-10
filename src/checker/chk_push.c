/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:14:00 by erivero-          #+#    #+#             */
/*   Updated: 2023/07/10 16:25:17 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	push(t_stack *src, t_stack *dst)
{
	dst->top++;
	dst->numbers[dst->top] = src->numbers[src->top];
	src->top--;
}

void	chk_pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
}

void	chk_pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
}
