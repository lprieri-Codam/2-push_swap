/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_push_to_a_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/07 17:41:07 by lprieri       #+#    #+#                 */
/*   Updated: 2024/04/09 13:24:47 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

/* --------------- PROTOTYPES --------------- */

void	set_target_b(t_stack *a, t_stack *b);
void	ps_push_to_a(t_info **info, t_stack **a, t_stack **b);
void	ps_prep_push_to_a(t_info **info, t_stack **stack, t_stack *top_node);
void	init_nodes_b(t_stack *a, t_stack *b);

/* --------------- FUNCTIONS --------------- */

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*a_iterator;
	t_stack	*target_node;
	int		best_match_i;

	while (b)
	{
		best_match_i = ps_count_nodes(a) + ps_count_nodes(b);
		a_iterator = a;
		while (a_iterator)
		{
			if (a_iterator->sorted_i > b->sorted_i
				&& a_iterator->sorted_i < best_match_i)
			{
				best_match_i = a_iterator->sorted_i;
				target_node = a_iterator;
			}
			a_iterator = a_iterator->next;
		}
		if (best_match_i == (ps_count_nodes(a) + ps_count_nodes(b)))
			b->target = find_min(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	ps_push_to_a(t_info **info, t_stack **a, t_stack **b)
{
	ps_prep_push_to_a(info, a, (*b)->target);
	if ((*a) == (*b)->target)
	{
		pa(info, a, b);
		(*a)->is_cheapest = false;
	}
}

void	ps_prep_push_to_a(t_info **info, t_stack **stack, t_stack *top_node)
{
	while (*stack != top_node)
	{
		if (top_node->above_median)
			ra(info, stack);
		else
			rra(info, stack);
	}
}

void	init_nodes_b(t_stack *a, t_stack *b)
{
	ps_indices_init(a);
	ps_indices_init(b);
	set_target_b(a, b);
}
