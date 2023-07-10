/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:55:26 by erivero-          #+#    #+#             */
/*   Updated: 2023/07/10 16:22:31 by erivero-         ###   ########.fr       */
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

t_stack	*init_stack_a(char **av)
{
	int		i;
	t_stack	*stack_a;

	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	stack_a->top = -1;
	stack_a->size = array_len(av);
	i = stack_a->size - 1;
	while (i >= 0)
	{
		stack_a->top++;
		stack_a->numbers[stack_a->top] = ft_atoi(av[i]);
		i--;
	}
	return (stack_a);
}
/* Inicializo top en -1 ya que si sólo tengo un número,
stará en la posición [0]. Así, puedo empezar el bucle sumando 
top++ y ya poniendo el número en esa posición */

t_stack	*init_stack_b(void)
{
	t_stack	*stack_b;

	stack_b = malloc(sizeof(t_stack));
	stack_b->top = -1;
	stack_b->size = 0;
	return (stack_b);
}

/* void	ft_leakss(void)
{
	system("leaks -q push_swap");
	atexit(ft_leakss);
} */

void	ft_error(int ac, char **arr)
{
	char	**ptr;

	ft_printf("Error\n");
	if (ac == 2)
	{
		ptr = arr;
		while (*ptr)
		{
			free(*ptr);
			ptr++;
		}
		free(arr);
	}
	exit(EXIT_FAILURE);
}

void	ft_free(int ac, char **arr, t_stack *stack_a, t_stack *stack_b)
{
	char	**ptr;

	if (ac == 2)
	{
		ptr = arr;
		while (*ptr)
		{
			free(*ptr);
			ptr++;
		}
		free(arr);
	}
	free(stack_a);
	free(stack_b);
	exit(EXIT_SUCCESS);
}
