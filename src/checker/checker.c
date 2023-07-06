/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:10:22 by erivero-          #+#    #+#             */
/*   Updated: 2023/07/06 19:12:09 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* strncmp devuelve un entero con la diferencia de caracteres,
si las dos strings son iguales, da 0 
Uso strNcmp porque juraría que strcmp no está en libft */
static void	make_instructions(char *inst, t_stack *stack_a, t_stack *stack_b, int ac, char **arr)
{
	if (!ft_strncmp(inst, "sa\n", 3))
		chk_sa(stack_a);
	else if (!ft_strncmp(inst, "sb\n", 3))
		chk_sb(stack_b);
	else if (!ft_strncmp(inst, "ss\n", 3))
		chk_ss(stack_a, stack_b);
	else if (!ft_strncmp(inst, "pa\n", 3))
		chk_pa(stack_a, stack_b);
	else if (!ft_strncmp(inst, "pb\n", 3))
		chk_pb(stack_a, stack_b);
	else if (!ft_strncmp(inst, "ra\n", 3))
		chk_ra(stack_a);
	else if (!ft_strncmp(inst, "rb\n", 3))
		chk_rb(stack_b);
	else if (!ft_strncmp(inst, "rr\n", 3))
		chk_rr(stack_a, stack_b);
	else if (!ft_strncmp(inst, "rra\n", 4))
		chk_rra(stack_a);
	else if (!ft_strncmp(inst, "rrb\n", 4))
		chk_rrb(stack_b);
	else if (!ft_strncmp(inst, "rrr\n", 4))
		chk_rrr(stack_a, stack_b);
	else
		ft_error(ac, arr);
}
void read_instructions(t_stack *stack_a, t_stack *stack_b, int ac, char **arr)
{
	char *inst;

	inst = get_next_line(0);
	while (inst)
	{
		make_instructions(inst, stack_a, stack_b, ac, arr);
		inst = get_next_line(0);
	}
}

bool sort_check(t_stack *stack_a)
{
	int	*num;
	int	i;

	num = stack_a->numbers;
	i = stack_a->top;
	while (i > 0)
	{
		if (num[i] > num[i - 1])
			return (false); // están mal ordenados
		i--;
	}
	return (true);	
}

int main (int ac, char **av)
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
	read_instructions(stack_a, stack_b, ac, arr);
	if (sort_check(stack_a) && stack_b->top < 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free(ac, arr, stack_a, stack_a);
}
