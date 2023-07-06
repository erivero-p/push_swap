/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:48:15 by erivero-          #+#    #+#             */
/*   Updated: 2023/07/06 18:42:12 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* void	ft_print_stack(t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i >= 0)
	{
		ft_printf("La posición %i es: %i\n", i, stack->numbers[i]);
		i--;
	}
} */

int	main(int ac, char **av)
{
	char	**arr;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	if (ac == 2)
		arr = ft_split(av[1], 32);
	else
		arr = av + 1;
	if (!check_args(arr))
		ft_error(ac, arr);
	stack_a = init_stack_a(arr);
	stack_b = init_stack_b();
	if (!check_order(stack_a))
	{
		if (stack_a->size < 7)
			sort_few(stack_a, stack_b);
		else if (stack_a->size <= 100)
			big_sorter(stack_a, stack_b, 5);
		else
			big_sorter(stack_a, stack_b, 11);
	}
	ft_free(ac, arr, stack_a, stack_a);
//	ft_print_stack(stack_a);
}
