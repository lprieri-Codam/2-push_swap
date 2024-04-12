/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_stack.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lisandro <lisandro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/06 19:59:24 by lisandro      #+#    #+#                 */
/*   Updated: 2024/04/10 15:08:23 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* --------------- PROTOTYPES --------------- */

void	ps_stack_init(t_stack **a, t_stack **current, int i, int value);
t_stack	*ps_stack_new(int index, int value);
void	ps_indices_init(t_stack *stack);;
void	ps_stack_clear(t_stack **stack);

/* --------------- FUNCTIONS --------------- */

/*	PS_STACK_INIT
*	Takes a pointer to stack 'a' and another to the current pointer in stack 'a'.
*	If stack 'a' is NULL it means we have to assign the new node to 'a'.
*	Else we assign it to the next pointer in the current pointer.
*	After the assignation of the node we update the current pointer.
*/
void	ps_stack_init(t_stack **a, t_stack **current, int i, int value)
{
	if (!*a)
	{
		*a = ps_stack_new(i, value);
		*current = *a;
	}
	else
	{
		(*current)->next = ps_stack_new(i, value);
		*current = (*current)->next;
	}
}

/*	PS_STACK_NEW
*	Creates a new stack node.
*	Assigns heap memory and initializes each variable.
*	Returns the newly created stack node.
*/
t_stack	*ps_stack_new(int index, int value)
{
	t_stack	*stack;

	stack = (t_stack *) malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = value;
	stack->index = index;
	stack->cost = -1;
	stack->is_cheapest = false;
	stack->above_median = false;
	stack->above_sorted_median = false;
	stack->next = NULL;
	stack->target = NULL;
	stack->is_first_stack = 0;
	return (stack);
}

/*	PS_INDICES_INIT
*	Iterates through a stack assigning indices to each node.
*	It also calculates the median
*	and sets the value of 'above_median' to its corresponding value.
*/
void	ps_indices_init(t_stack *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = ps_count_nodes(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

/*	PS_STACK_CLEAR
*	Calls this function recursively to free each node of a stack.
*	It frees the stack and sets the pointer to NULL.
*/
void	ps_stack_clear(t_stack **stack)
{
	if (!(*stack))
		return ;
	ps_stack_clear(&(*stack)->next);
	free(*stack);
	(*stack) = NULL;
}
