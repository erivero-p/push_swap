/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:48:15 by erivero-          #+#    #+#             */
/*   Updated: 2023/06/26 15:19:10 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
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
	init_stack_a(stack_a, bid);
	init_stack_b(stack_b);
}
