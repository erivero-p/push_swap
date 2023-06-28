/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:26:10 by erivero-          #+#    #+#             */
/*   Updated: 2023/06/28 12:28:44 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pb(t_stack *stack_a, t_stack *stack_b)
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
}
