/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:16:06 by erivero-          #+#    #+#             */
/*   Updated: 2023/06/29 13:31:09 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdbool.h>

int	search_max(t_stack *stack_a)
{
	int	max;
	int	len;

	max = stack_a->numbers[0];
	len = stack_a->top;
	while (len-- > 0)
	{
		if (max < stack_a->numbers[len])
			max = stack_a->numbers[len];
	}
	return (max);
}

int	search_min(t_stack *stack_a)
{
	int	max;
	int	len;

	max = stack_a->numbers[0];
	len = stack_a->top;
	while (len-- > 0)
	{
		if (max > stack_a->numbers[len])
			max = stack_a->numbers[len];
	}
	return (max);
}

bool	compare_chunk(int start, int end)
{
	int	len;

	len = stack_a->top;
	while (len-- > 0)
	{
		if (stack_a->numbers[len] >= start && stack_a->numbers[len] <= end)
			return (true);
	}
	return (false);
}
