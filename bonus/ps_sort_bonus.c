/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_sort_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/07 13:58:37 by lprieri       #+#    #+#                 */
/*   Updated: 2024/04/09 13:24:50 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

/* --------------- PROTOTYPES --------------- */

void	ps_vurksort(t_info **info, t_stack **a, t_stack **b);
void	ps_push_to_b(t_info **info, t_stack **a, t_stack **b);
void	ps_push_twice_to_b(t_info **info, t_stack **a, t_stack **b);
void	ps_push_cheapest_to_b(t_info **info, t_stack **a, t_stack **b);
void	ps_prep_nodes(t_info **info, t_stack **a, t_stack **b,
			t_stack *cheapest);

/* --------------- FUNCTIONS --------------- */

void	ps_vurksort(t_info **info, t_stack **a, t_stack **b)
{
	if (*info && (*info)->nodes_nbr == 1)
		return ;
	ps_push_to_b(info, a, b);
	while (*b)
	{
		init_nodes_b(*a, *b);
		ps_push_to_a(info, a, b);
	}
	while ((*a)->value != find_min(*a)->value)
	{
		if (find_min(*a)->above_median)
			ra(info, a);
		else
			rra(info, a);
	}
}

void	ps_push_to_b(t_info **info, t_stack **a, t_stack **b)
{
	int	nodes_a;
	int	nodes_b;

	ps_push_twice_to_b(info, a, b);
	nodes_a = ps_count_nodes(*a);
	nodes_b = ps_count_nodes(*b);
	while (nodes_a > 3 && ps_is_sorted(*a) != 1)
	{
		if (nodes_a == nodes_b && (*info)->nodes_nbr > 100)
		{
			(*info)->second_stack = 1;
			(*info)->upper_node = *b;
			(*info)->lower_node = get_i_node(*b, nodes_b - 1);
		}
		ps_push_cheapest_to_b(info, a, b);
		nodes_a--;
		nodes_b++;
	}
	if (nodes_a == 3 && ps_is_sorted(*a) != 1)
		ps_sort_three(info, a);
}

void	ps_push_twice_to_b(t_info **info, t_stack **a, t_stack **b)
{
	if (!(*a) || ps_is_sorted(*a))
		return ;
	pb(info, a, b);
	if (ps_count_nodes(*a) <= 3 || ps_is_sorted(*a))
		return ;
	pb(info, a, b);
}

void	ps_push_cheapest_to_b(t_info **info, t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	if ((*info)->second_stack)
	{
		ps_indices_init(*a);
		ps_indices_init(*b);
	}
	ps_set_target_a(*info, *a, *b);
	ps_calculate_costs(*a, *b);
	cheapest = ps_set_cheapest(*info, *a);
	ps_prep_nodes(info, a, b, cheapest);
	pb(info, a, b);
	(*b)->is_cheapest = false;
}

void	ps_prep_nodes(t_info **info, t_stack **a, t_stack **b,
			t_stack *cheapest)
{
	while (*a != cheapest || *b != cheapest->target)
	{
		if (*a != cheapest && *b != cheapest->target
			&& cheapest->above_median && cheapest->target->above_median)
			rr(info, a, b);
		else if (*a != cheapest && *b != cheapest->target
			&& !cheapest->above_median && !cheapest->target->above_median)
			rrr(info, a, b);
		else if (*a != cheapest || *b != cheapest->target)
		{
			if (*a != cheapest && cheapest->above_median)
				ra(info, a);
			else if (*a != cheapest && !cheapest->above_median)
				rra(info, a);
			if (*b != cheapest->target && cheapest->target->above_median)
				rb(info, b);
			else if (*b != cheapest->target && !cheapest->target->above_median)
				rrb(info, b);
		}
	}
}
