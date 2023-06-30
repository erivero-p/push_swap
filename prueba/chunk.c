/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:16:06 by erivero-          #+#    #+#             */
/*   Updated: 2023/06/30 13:26:30 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdbool.h>

int	chunk_size(t_stack *stack_a)
{
	int	max;
	int	len;
	int min;
	int size;

	max = stack_a->numbers[0];
	min = max;
	len = stack_a->top;
	while (len-- > 0)
	{
		if (max < stack_a->numbers[len])
			max = stack_a->numbers[len];
		if (min > stack_a->numbers[len])
			min = stacK_a->numbers[len];
	}
	size = max - min;
	return (size);
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

