/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 14:17:25 by lprieri       #+#    #+#                 */
/*   Updated: 2024/02/29 16:26:54 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/* Generic swap function */
void	swap(t_stack **stack)
{
	t_stack	*helper;

	if (!(*stack) || !(*stack)->next)
		return ;
	helper = (*stack);
	(*stack) = (*stack)->next;
	helper->next = (*stack)->next;
	(*stack)->next = helper;
}

/*	SWAP A
*
*	Swaps the first 2 elements at the top of stack a.
*	Does nothing if there is only one or no elements.
*/
void	sa(t_info **info, t_stack **a_stack)
{
	t_stack	*helper;

	if (!(*a_stack) || !(*a_stack)->next)
		return ;
	helper = (*a_stack);
	(*a_stack) = (*a_stack)->next;
	helper->next = (*a_stack)->next;
	(*a_stack)->next = helper;
	write(1, "sa\n", 3);
	(*info)->total_cost++;
}

/*	SWAP B
*
*	Swaps the first 2 elements at the top of stack a.
*	Does nothing if there is only one or no elements.
*/
void	sb(t_info **info, t_stack **b_stack)
{
	t_stack	*helper;

	if (!(*b_stack) || !(*b_stack)->next)
		return ;
	helper = (*b_stack);
	(*b_stack) = (*b_stack)->next;
	helper->next = (*b_stack)->next;
	(*b_stack)->next = helper;
	write(1, "sb\n", 3);
	(*info)->total_cost++;
}

/*	SWAP SWAP
*
*	SWAP A & SWAP B at the same time.
*/
void	ss(t_info **info, t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*a_helper;
	t_stack	*b_helper;

	if (!(*a_stack) || !(*a_stack)->next)
		return ;
	a_helper = (*a_stack);
	(*a_stack) = (*a_stack)->next;
	a_helper->next = (*a_stack)->next;
	(*a_stack)->next = a_helper;
	if (!(*b_stack) || !(*b_stack)->next)
		return ;
	b_helper = (*b_stack);
	(*b_stack) = (*b_stack)->next;
	b_helper->next = (*b_stack)->next;
	(*b_stack)->next = b_helper;
	write(1, "ss\n", 3);
	(*info)->total_cost++;
}
