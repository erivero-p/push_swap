/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:55:26 by erivero-          #+#    #+#             */
/*   Updated: 2023/07/07 13:15:41 by erivero-         ###   ########.fr       */
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
	stack_a->top = -1; // -1 y no 0 para poder empezar sumando en top. Si sumo al final y no al principio, voy a estar sumando uno de más, aunque no lo rellene.
	stack_a->size = array_len(av);
	i = stack_a->size - 1;
// Necesito un iterador porque si uso while(av[stack_a->top]) hago una iteración de más
	while (i >= 0)
	{
//		ft_printf("top is %i\n", stack_a->top);

		stack_a->top++;
		stack_a->numbers[stack_a->top] = ft_atoi(av[i]);
		i--;
	}
//	ft_printf("finally top is %i\n", stack_a->top);

	return (stack_a);
}

t_stack	*init_stack_b(void)
{
	t_stack	*stack_b;

	stack_b = malloc(sizeof(t_stack));
	ft_printf("ALOHA\n");
	stack_b->top = -1; //para ir al 0 cuando empiece a pushear
	stack_b->size = 0;
	return (stack_b);
}

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

	(void) stack_b;
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
//	free(stack_b);
	exit(EXIT_SUCCESS);
}
