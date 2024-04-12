/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 16:40:43 by lprieri       #+#    #+#                 */
/*   Updated: 2024/03/07 13:56:13 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*	PUSH A
*
*	Takes the first element at the top of stack b
*	and puts it at the top of stack a.
*	Does nothing if stack b is empty.
*/
void	pa(t_info **info, t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*helper;

	if (!(*b_stack))
		return ;
	helper = (*b_stack);
	(*b_stack) = (*b_stack)->next;
	if (!(*a_stack))
	{
		(*a_stack) = helper;
		(*a_stack)->next = NULL;
	}
	else
	{
		helper->next = (*a_stack);
		(*a_stack) = helper;
	}
	(*info)->total_cost++;
	write(1, "pa\n", 3);
}

/*	PUSH B
*
*	Takes the first element at the top of stack a
*	and puts it at the top of stack b.
*	Does nothing if stack a is empty.
*/
void	pb(t_info **info, t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*helper;

	if (!(*a_stack))
		return ;
	helper = (*a_stack);
	(*a_stack) = (*a_stack)->next;
	if (!(*b_stack))
	{
		(*b_stack) = helper;
		(*b_stack)->next = NULL;
	}
	else
	{
		helper->next = (*b_stack);
		(*b_stack) = helper;
	}
	(*info)->total_cost++;
	write(1, "pb\n", 3);
}
