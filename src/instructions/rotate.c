/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/20 16:47:56 by lprieri       #+#    #+#                 */
/*   Updated: 2024/03/07 13:55:17 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/* Generic rotate function */
void	rotate(t_stack **stack)
{
	t_stack	*helper;
	t_stack	*iterator;

	helper = (*stack);
	if (!helper || !helper->next)
		return ;
	(*stack) = (*stack)->next;
	iterator = (*stack);
	while (iterator->next != NULL)
		iterator = iterator->next;
	helper->next = NULL;
	iterator->next = helper;
}

/*	ROTATE A
*
*	Shifts up all the elements of stack a by 1.
*	The first element becomes the last one.
*/
void	ra(t_info **info, t_stack **a_stack)
{
	t_stack	*helper;
	t_stack	*iterator;

	helper = (*a_stack);
	if (!helper || !helper->next)
		return ;
	(*a_stack) = (*a_stack)->next;
	helper->next = NULL;
	iterator = (*a_stack);
	while (iterator->next != NULL)
		iterator = iterator->next;
	iterator->next = helper;
	write(1, "ra\n", 3);
	(*info)->total_cost++;
}

/*	ROTATE B
*
*	Shifts up all the elements of stack b by 1.
*	The first element becomes the last one.
*/
void	rb(t_info **info, t_stack **b_stack)
{
	t_stack	*helper;
	t_stack	*iterator;

	helper = (*b_stack);
	if (!helper || !helper->next)
		return ;
	(*b_stack) = (*b_stack)->next;
	helper->next = NULL;
	iterator = (*b_stack);
	while (iterator->next != NULL)
		iterator = iterator->next;
	iterator->next = helper;
	write(1, "rb\n", 3);
	(*info)->total_cost++;
}

/*	ROTATE A & ROTATE B
*
*	ra and rb at the same time.
*/
void	rr(t_info **info, t_stack **a_stack, t_stack **b_stack)
{
	rotate(a_stack);
	rotate(b_stack);
	write(1, "rr\n", 3);
	(*info)->total_cost++;
}
