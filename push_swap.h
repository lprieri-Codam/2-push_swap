/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 14:01:13 by lprieri       #+#    #+#                 */
/*   Updated: 2024/04/09 12:30:25 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdbool.h>
# include <limits.h>

/* MACROS */
# define MAX_INT 2147483647
# define MIN_INT -2147483648

/* STRUCTS */
typedef struct s_stack
{
	int				value;
	int				index;
	int				sorted_i;
	int				cost;
	bool			is_cheapest;
	bool			above_median;
	bool			above_sorted_median;
	bool			is_first_stack;
	struct s_stack	*next;
	struct s_stack	*target;
}	t_stack;

typedef struct s_info
{
	int		total_cost;
	int		nodes_nbr;
	t_stack	*upper_node;
	t_stack	*lower_node;
	int		second_stack;
}	t_info;

typedef struct s_cost
{
	int		final_cost;
	int		sa;
	int		sb;
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
}	t_cost;

/* INSTRUCTIONS */
void	swap(t_stack **stack);
void	sa(t_info **info, t_stack **a_stack);
void	sb(t_info **info, t_stack **b_stack);
void	ss(t_info **info, t_stack **a_stack, t_stack **b_stack);
void	pa(t_info **info, t_stack **a_stack, t_stack **b_stack);
void	pb(t_info **info, t_stack **a_stack, t_stack **b_stack);
void	rotate(t_stack **stack);
void	ra(t_info **info, t_stack **a_stack);
void	rb(t_info **info, t_stack **b_stack);
void	rr(t_info **info, t_stack **a_stack, t_stack **b_stack);
void	r_rotate(t_stack **stack);
void	rra(t_info **info, t_stack **a_stack);
void	rrb(t_info **info, t_stack **b_stack);
void	rrr(t_info **info, t_stack **a_stack, t_stack **b_stack);

/* DOUBLE STACK UTILS */
int		count_from_x_to_y(t_stack *x, t_stack *y);
int		is_in_x_to_y(t_stack *q, t_stack *x, t_stack *y);
t_stack	*skip_from_x_to_y(t_stack **x, t_stack *y);
void	set_first_stack(t_stack *x, t_stack *y);
void	apply_cost_from_x_to_y(t_info *info, t_stack **x, t_stack *y);

/* FREE */
void	ps_free(void **content);
void	ps_free_array(void ***array);

/* INFO */
int		ps_info_init(t_info **info, t_stack *a);

/* PARSE */
int		ps_parse(t_info **info, t_stack **a, int argc, char *argv[]);
int		ps_parse_arg(t_stack **a, char *str);
int		ps_parse_args(t_stack **a, int argc, char *argv[]);
int		ps_has_repetitions(t_stack *stack);

/* PRESORT */
int		ps_presort(t_info *info, t_stack *a);

/* PUSH TO A */
void	set_target_b(t_stack *a, t_stack *b);
void	ps_push_to_a(t_info **info, t_stack **a, t_stack **b);
void	ps_prep_push_to_a(t_info **info, t_stack **stack, t_stack *top_node);
void	init_nodes_b(t_stack *a, t_stack *b);

/* PUSH TO B */
void	ps_set_target_a(t_info *info, t_stack *a, t_stack *b);
t_stack	*ps_find_best_match(t_info *info,
			t_stack *seeker, t_stack **targeted_stack);
void	ps_calculate_costs(t_stack *a, t_stack *b);
t_stack	*ps_set_cheapest(t_info *info, t_stack *stack);
int		ps_check_for_double_stack(t_info *info, t_stack **skip_stack);

/* SORT THREE */
void	ps_sort_three(t_info **info, t_stack **a);

/* SORT */
void	ps_vurksort(t_info **info, t_stack **a, t_stack **b);
void	ps_push_to_b(t_info **info, t_stack **a, t_stack **b);
void	ps_push_twice_to_b(t_info **info, t_stack **a, t_stack **b);
void	ps_push_cheapest_to_b(t_info **info, t_stack **a, t_stack **b);
void	ps_prep_nodes(t_info **info, t_stack **a, t_stack **b,
			t_stack *cheapest);

/* STACK UTILS */
void	ps_stack_print_full(t_stack *stack);
void	ps_stack_print(t_stack *stack);
int		ps_count_nodes(t_stack *stack);
t_stack	*ps_get_cheapest(t_stack *stack);
t_stack	*find_max(t_info *info, t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*get_i_node(t_stack *stack, int index);

/* STACK */
void	ps_stack_init(t_stack **a, t_stack **current, int i, int value);
t_stack	*ps_stack_new(int index, int value);
void	ps_indices_init(t_stack *stack);
void	ps_stack_clear(t_stack **stack);

/* UTILS */
int		ps_isdigit(char *arg);
int		ps_is_sorted(t_stack *stack);
int		ps_atoi(const char *str, int *number);
// int	ps_is_repeated(t_stack **a_stack, int number);
// int	ps_has_repetitions(t_stack **a_stack);

#endif