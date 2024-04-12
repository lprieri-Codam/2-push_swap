/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_sort.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/07 13:58:37 by lprieri       #+#    #+#                 */
/*   Updated: 2024/04/11 16:42:59 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* --------------- PROTOTYPES --------------- */

void	ps_vurksort(t_info **info, t_stack **a, t_stack **b);
void	ps_push_to_b(t_info **info, t_stack **a, t_stack **b);
void	ps_push_twice_to_b(t_info **info, t_stack **a, t_stack **b);
void	ps_push_cheapest_to_b(t_info **info, t_stack **a, t_stack **b);
void	ps_prep_nodes(t_info **info, t_stack **a, t_stack **b,
			t_stack *cheapest);

/* --------------- FUNCTIONS --------------- */

/*	VURKSORT
*	Implements the turksort algorithm with a slight variation.
*	Once half of the total nodes have been pushed to B
*	it ignores the already existing stack in B
*	and pushes new nodes into a new stack that's on top of the previous one.
*/
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

/*	PUSH TO B
*	Pushes two inital nodes to B.
*	Then it pushes half of the A stack into B by selecting the cheapest node.
*	After half of the stack has been pushed, it sets the flag 'second_stack'
*	to TRUE, and it initializes the variables 'upper_node' and 'lower_node'
*	which keep track of the previous stack in B (to ignore it).
*	Then it keeps pushing nodes into the new stack in B.
*	At the end it sorts 3 nodes in A.
*/
void	ps_push_to_b(t_info **info, t_stack **a, t_stack **b)
{
	int	nodes_a;
	int	nodes_b;

	ps_push_twice_to_b(info, a, b);
	nodes_a = ps_count_nodes(*a);
	nodes_b = ps_count_nodes(*b);
	while (nodes_a > 3 && ps_is_sorted(*a) != 1)
	{
		if (nodes_a <= nodes_b && (*info)->nodes_nbr > 100)
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

/*	PUSH TWICE TO B
*	Pushes the 2 top nodes in A to B.
*/
void	ps_push_twice_to_b(t_info **info, t_stack **a, t_stack **b)
{
	if (!(*a) || ps_is_sorted(*a))
		return ;
	pb(info, a, b);
	if (ps_count_nodes(*a) <= 3 || ps_is_sorted(*a))
		return ;
	pb(info, a, b);
}

/*	PUSH CHEAPEST TO B
*	It sets a target node for each node in A.
*	It calculates the costs for pushing each node.
*	It finds the cheapest node.
*	It arranges both stacks, A and B, to be ready to push.
*	When it pushes the node to B it resets the 'is_cheapest' flag.
*/
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

/*	PREPARE NODES
*	It rotates or reverse rotates stacks A and B
*	so that the cheapest node of stack A is on top
*	and the target of that node is on top of stack B.
*	The function looks to minimize costs by rotating both stacks if applicable.
*/
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
