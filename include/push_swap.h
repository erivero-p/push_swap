#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int	numbers[1024]; //max que puede ocupar un array
	int	top; // esto va a ir variando
	int	size; // esto es fijo (count + 1)
// dará problema por no inicializarlas cuando no las uso? en números pequeños
	int	start; // el número más pequeño y start del chunk
//	int	max; // el número más grande y fin del último chunk

} t_stack;

bool	check_args(char **av);
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
