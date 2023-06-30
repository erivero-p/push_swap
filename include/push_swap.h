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
	int	start; // el número más pequeño y start del chunk
	int	max; // el número más grande y fin del último chunk

} t_stack;

bool	check_args(char **av);
t_stack	*init_stack_a(char **av);
t_stack	*init_stack_b(void);
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
void	ft_error(void);






#endif