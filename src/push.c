/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:26:10 by erivero-          #+#    #+#             */
/*   Updated: 2023/06/30 16:02:46 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* void	pb(t_stack *stack_a, t_stack *stack_b)
{
	stack_b->top++;
	stack_b[stack_b->top] = stack_a[stack_a->top];
	stack_a->top--;
	ft_printf("pa\n");
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->top++;
	stack_a[stack_a->top] = stack_b[stack_b->top];
	stack_b->top--;
	ft_printf("pb\n");
} */

void	push(t_stack *src, t_stack *dst)
{
	dst->top++;
	dst->numbers[dst->top] = src->numbers[src->top];
//	ft_printf("el número pusheado es: %i\n", dst->numbers[dst->top]);
	src->top--;
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
