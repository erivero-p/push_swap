/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:48:15 by erivero-          #+#    #+#             */
/*   Updated: 2023/06/27 16:25:03 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(void)
{
	ft_printf("Error");
	exit(EXIT_FAILURE);
}

void ft_print_stack(t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i >= 0)
	{
		ft_printf("La posición %i es: %i\n", i, stack->numbers[i]);
		i--;
	}
}

int	main(int ac, char **av)
{
	char	**bid;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		ft_error();
	if (ac == 2)
		bid = ft_split(av[1], 32);
	else
		bid = av + 1;
	if (!check_args(bid))
		ft_error();
	stack_a = init_stack_a(bid);
	stack_b = init_stack_b();
	if (stack_a->size < 7)
		sort_few(stack_a, stack_b);
}
