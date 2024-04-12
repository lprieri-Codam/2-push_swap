/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_double_stack_utils.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lisandro <lisandro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/06 16:12:37 by lisandro      #+#    #+#                 */
/*   Updated: 2024/04/10 13:51:11 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* --------------- PROTOTYPES --------------- */

int		count_from_x_to_y(t_stack *x, t_stack *y);
int		is_in_x_to_y(t_stack *q, t_stack *x, t_stack *y);
t_stack	*skip_from_x_to_y(t_stack **x, t_stack *y);
void	set_first_stack(t_stack *x, t_stack *y);
void	apply_cost_from_x_to_y(t_info *info, t_stack **x, t_stack *y);

/* --------------- FUNCTIONS --------------- */

/*	COUNT FROM X TO Y 
*	Counts the number of nodes from a starting point x
*	to a finishing node y.
*/
int	count_from_x_to_y(t_stack *x, t_stack *y)
{
	int	counter;

	counter = 0;
	while (x)
	{
		if (x == y)
			return (counter);
		counter++;
		x = x->next;
	}
	return (0);
}

/*	IS IN X TO Y
*	Checks whether a stack 'q' is within a sequence of nodes
*	that ranges from 'x' to 'y'.
*	Returns 1 on success, or 0 on failure.
*/
int	is_in_x_to_y(t_stack *q, t_stack *x, t_stack *y)
{
	while (x && x != y)
	{
		if (q == x)
			return (1);
		x = x->next;
	}
	if (q == x)
		return (1);
	return (0);
}

/*	SKIP FROM X TO Y
*	Takes the pointer to a (pointer to) stack 'x',
*	and a pointer to stack 'y'.
*	Iterates stack 'x' until it reaches the node 'y'.
*	Returns the node after 'y' on success or NULL on failure.
*/
t_stack	*skip_from_x_to_y(t_stack **x, t_stack *y)
{
	if (!*x || !y)
		return (NULL);
	while (*x)
	{
		if (*x == y)
			return (*x = (*x)->next, *x);
		*x = (*x)->next;
	}
	if (*x == y)
		return (*x = (*x)->next, *x);
	return (NULL);
}

/*	SET FIRST STACK
*	Takes two stack pointers,
*	and sets every node's 'is_first_stack' flag
*	contained between these two nodes to true (1).
*/
void	set_first_stack(t_stack *x, t_stack *y)
{
	if (!x || !y)
		return ;
	while (x)
	{
		if (x == y)
		{
			x->is_first_stack = 1;
			x = x->next;
			return ;
		}
		x->is_first_stack = 1;
		x = x->next;
	}
	if (x == y)
	{
		x->is_first_stack = 1;
		x = x->next;
	}
}

/*	APPLY COST FROM X TO Y
*	Takes a pointer to a pointer to 'x' and a pointer to 'y'.
*	Iterates the stack from 'x' to 'y', while setting the cost of each node
*	to the total number of nodes (globally).
*/
void	apply_cost_from_x_to_y(t_info *info, t_stack **x, t_stack *y)
{
	if (!*x || !y)
		return ;
	while (*x)
	{
		if (*x == y)
		{
			(*x)->cost = info->nodes_nbr;
			*x = (*x)->next;
			return ;
		}
		(*x)->cost = info->nodes_nbr;
		*x = (*x)->next;
	}
	if (*x == y)
	{
		(*x)->cost = info->nodes_nbr;
		*x = (*x)->next;
	}
}
