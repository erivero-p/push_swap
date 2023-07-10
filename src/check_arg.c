/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:42:06 by erivero-          #+#    #+#             */
/*   Updated: 2023/07/10 15:09:05 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static bool	is_number(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-' || num[i] == '+')
		i++;
	while (num[i])
	{
		if (num[i] >= '0' && num[i] <= '9')
			i++;
		else
			break ;
	}
	if (num[i] == '\0')
		return (true);
	else
		return (false);
}
/* Para comparar los números y comprobar que no sean iguales, 
como no se pueden hacer comparaciones directas de dos strings, 
puedo pasarlas por atoi (que es lo que hago en este caso) o usar strncmp */

static bool	check_rep(char **av, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (ft_atoi(av[j]) == ft_atoi(av[i]))
			return (false);
		j++;
	}
	return (true);
}

bool	check_args(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!is_number(av[i]))
			return (false);
		if (!(ft_atoi(av[i]) > INT_MIN && ft_atoi(av[i]) < INT_MAX))
			return (false);
		if (!check_rep(av, i))
			return (false);
		i++;
	}
	return (true);
}

bool	check_order(t_stack	*stack_a)
{
	int	i;

	i = stack_a->top;
	while (i > 0)
	{
		if (stack_a->numbers[i] > stack_a->numbers[i - 1])
			return (false);
		i--;
	}
	return (true);
}
