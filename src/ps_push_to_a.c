/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_push_to_a.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/07 17:41:07 by lprieri       #+#    #+#                 */
/*   Updated: 2024/04/12 12:25:07 by lisandro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* --------------- PROTOTYPES --------------- */

void	set_target_b(t_stack *a, t_stack *b);
void	ps_push_to_a(t_info **info, t_stack **a, t_stack **b);
void	ps_prep_push_to_a(t_info **info, t_stack **stack, t_stack *top_node);
void	init_nodes_b(t_stack *a, t_stack *b);

/* --------------- FUNCTIONS --------------- */

/*	SET TARGET FOR B
*	It sets the 'A' target node for each node in 'B'.
*	The target node (TN) is the node to push on top of.
*	Whichever node in 'A' has the lowest value (or sorted index)
*	and at the same time is bigger than the value being pushed from 'B',
*	that becomes the target node in 'A' for the 'B' node.
*/
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

/*	PUSH TO A
*	Prepares the 'A' stack so that the target node is at the top.
*	Pushes the node from 'B' to 'A', reseting the 'is_cheapest' value to false.
*/
void	ps_push_to_a(t_info **info, t_stack **a, t_stack **b)
{
	ps_prep_push_to_a(info, a, (*b)->target);
	if ((*a) == (*b)->target)
	{
		pa(info, a, b);
		(*a)->is_cheapest = false;
	}
}

/*	PREPARE TO PUSH TO A
*	Prepares the 'A' stack to push from 'B'.
*	If the target node is above the median it rotates the stack
*	until the target node is at the top,
*	else it reverse rotates the stack.
*/
void	ps_prep_push_to_a(t_info **info, t_stack **stack, t_stack *top_node)
{
	if (!*stack || !top_node)
		return ;
	while (*stack != top_node)
	{
		if (top_node->above_median)
			ra(info, stack);
		else
			rra(info, stack);
	}
}

/*	INITIALIZE B NODES
*	This function assigns indices to each element of each stack,
*	based on the current number of nodes and their current position.
*	Then it calls the function to set targets for each node in 'B'.
*/
void	init_nodes_b(t_stack *a, t_stack *b)
{
	ps_indices_init(a);
	ps_indices_init(b);
	set_target_b(a, b);
}
