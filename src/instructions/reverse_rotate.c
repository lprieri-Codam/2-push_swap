/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/20 17:28:00 by lprieri       #+#    #+#                 */
/*   Updated: 2024/03/07 13:55:42 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/* Generic reverse rotate function */
void	r_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	first = (*stack);
	if (!first || !first->next)
		return ;
	last = (*stack);
	while (last->next->next != NULL)
		last = last->next;
	last->next->next = (*stack);
	(*stack) = last->next;
	last->next = NULL;
}

/*	REVERSE ROTATE A
*
*	Shifts down all the elements of stack a by 1.
*	The last element becomes the first one.
*/
void	rra(t_info **info, t_stack **a_stack)
{
	t_stack	*first;
	t_stack	*last;

	first = (*a_stack);
	if (!first || !first->next)
		return ;
	last = (*a_stack);
	while (last->next->next != NULL)
		last = last->next;
	last->next->next = (*a_stack);
	(*a_stack) = last->next;
	last->next = NULL;
	write(1, "rra\n", 4);
	(*info)->total_cost++;
}

/*	REVERSE ROTATE B
*
*	Shifts down all the elements of stack b by 1.
*	The last element becomes the first one.
*/
void	rrb(t_info **info, t_stack **b_stack)
{
	t_stack	*first;
	t_stack	*last;

	first = (*b_stack);
	if (!first || !first->next)
		return ;
	last = (*b_stack);
	while (last->next->next != NULL)
		last = last->next;
	last->next->next = (*b_stack);
	(*b_stack) = last->next;
	last->next = NULL;
	write(1, "rrb\n", 4);
	(*info)->total_cost++;
}

/*	REVERSE ROTATE A & REVERSE ROTATE B
*
*	Reverse rotate a & b at the same time.
*/
void	rrr(t_info **info, t_stack **a_stack, t_stack **b_stack)
{
	r_rotate(a_stack);
	r_rotate(b_stack);
	write(1, "rrr\n", 4);
	(*info)->total_cost++;
}
