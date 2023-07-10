/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erivero- <erivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:10:22 by erivero-          #+#    #+#             */
/*   Updated: 2023/07/10 16:10:23 by erivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int	numbers[1024];
	int	top;
	int	size;
	int	start;
}	t_stack;

/* La estructura contiene:
- un array de enteros con el tamaño máximo que podría tener (1024)
- top, que es la posición de arriba del todo de cada stack, y que irá variando
- size, el tamaño total del array de enteros (top + 1)
- start: el número más pequeño, servirá como start del primer chunk. */

bool	check_args(char **av);
bool	check_order(t_stack	*stack_a);
t_stack	*init_stack_a(char **av);
t_stack	*init_stack_b(void);
void	ft_error(int ac, char **arr);
void	ft_free(int ac, char **arr, t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	sort_few(t_stack *stack_a, t_stack *stack_b);
void	push_chunks(t_stack *stack_a, t_stack *stack_b, int stack_count);
void	big_sorter(t_stack *stack_a, t_stack *stack_b, int stack_count);
bool	check_order(t_stack	*stack_a);

void	chk_sa(t_stack *stack_a);
void	chk_sb(t_stack *stack_b);
void	chk_ss(t_stack *stack_a, t_stack *stack_b);
void	chk_pa(t_stack *stack_a, t_stack *stack_b);
void	chk_pb(t_stack *stack_a, t_stack *stack_b);
void	chk_ra(t_stack *stack_a);
void	chk_rb(t_stack *stack_b);
void	chk_rr(t_stack *stack_a, t_stack *stack_b);
void	chk_rra(t_stack *stack_a);
void	chk_rrb(t_stack *stack_b);
void	chk_rrr(t_stack *stack_a, t_stack *stack_b);

#endif
