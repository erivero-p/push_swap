/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:57:18 by erivero-          #+#    #+#             */
/*   Updated: 2023/06/27 16:12:46 by erivero-         ###   ########.fr       */
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
	if (n[2] > n[1] && n[2] > n[0] && n[1] < n[0])//  3  1  2
		ra(stack_a);
	if (n[2] < n[1] && n[2] > n[0] && n[1] > n[0])//  2  3  1
		rra(stack_a);
	if (n[2] < n[1] && n[2] < n[0] && n[1] > n[0])//  1  3  2
	{
		rra(stack_a);
		sa(stack_a);
	}
	if (n[2] > n[1] && n[2] > n[0] && n[1] > n[0])//  3  2  1
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	sort_few(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 3)
		sort_three(stack_a);
	(void)stack_b;

}
