/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_stack_bonus.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lisandro <lisandro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/06 19:59:24 by lisandro      #+#    #+#                 */
/*   Updated: 2024/04/09 13:24:54 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

/* --------------- PROTOTYPES --------------- */

void	ps_stack_init(t_stack **a, t_stack **current, int i, int value);
t_stack	*ps_stack_new(int index, int value);
void	ps_indices_init(t_stack *stack);;
void	ps_stack_clear(t_stack **stack);

/* --------------- FUNCTIONS --------------- */

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

void	ps_stack_clear(t_stack **stack)
{
	if (!(*stack))
		return ;
	ps_stack_clear(&(*stack)->next);
	free(*stack);
	(*stack) = NULL;
}
