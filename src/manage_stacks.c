/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:55:26 by erivero-          #+#    #+#             */
/*   Updated: 2023/06/27 11:45:40 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	array_len(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

void	init_stack_a(t_stack *stack_a, char **av)
{
	int	i;

	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	stack_a->top = -1; // -1 y no 0 para poder empezar sumando en top. Si sumo al final y no al principio, voy a estar sumando uno de más, aunque no lo rellene.
	stack_a->size = array_len(av);
	i = stack_a->size - 1;

	while (av[stack_a->top])
	{
		stack_a->top++;
		stack_a->numbers[stack_a->top] = ft_atoi(av[i]);
		i--;
	}
}

void	init_stack_b(t_stack *stack_b)
{
	stack_b = malloc(sizeof(t_stack));
	stack_b->top = -1; //para ir al 0 cuando empiece a pushear
	stack_b->size = 0;
}
