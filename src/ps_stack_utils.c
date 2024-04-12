/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_stack_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lisandro <lisandro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/06 21:40:34 by lisandro      #+#    #+#                 */
/*   Updated: 2024/04/11 16:28:51 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* --------------- PROTOTYPES --------------- */

int		ps_count_nodes(t_stack *stack);
t_stack	*ps_get_cheapest(t_stack *stack);
t_stack	*find_max(t_info *info, t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*get_i_node(t_stack *stack, int index);
// void	ps_stack_print_full(t_stack *stack);
// void	ps_stack_print(t_stack *stack);

/* --------------- FUNCTIONS --------------- */

/*	COUNT NODES
*	Returns the number of nodes in a stack.
*/
int	ps_count_nodes(t_stack *stack)
{
	int		i;

	i = 0;
	if (!stack)
		return (i);
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

/*	GET CHEAPEST
*	Returns the node that's flagges as the cheapest node.
*	Returns NULL on failure.
*/
t_stack	*ps_get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->is_cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

/*	FIND MAX
*	Compares each node with each other in the stack
*	and returns the node with the highest value.
*/
t_stack	*find_max(t_info *info, t_stack *stack)
{
	t_stack	*max_node;
	int		max_i;

	if (!stack)
		return (NULL);
	max_node = stack;
	max_i = -1;
	while (stack)
	{
		if (info->second_stack
			&& is_in_x_to_y(stack, info->upper_node, info->lower_node))
		{
			skip_from_x_to_y(&stack, info->lower_node);
			continue ;
		}
		if (stack->sorted_i > max_i)
		{
			max_i = stack->sorted_i;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

/*	FIND MIN
*	Compares each node with each other in the stack
*	and returns the node with the lowest value.
*/
t_stack	*find_min(t_stack *stack)
{
	t_stack	*min_node;
	int		min_i;

	if (!stack)
		return (NULL);
	min_i = stack->sorted_i;
	while (stack)
	{
		if (stack->sorted_i <= min_i)
		{
			min_i = stack->sorted_i;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

/*	GET i_NODE
*	Returns the node at i position in the stack.
*/
t_stack	*get_i_node(t_stack *stack, int index)
{
	int	i;

	if (!stack)
		return (NULL);
	i = 0;
	while (stack && i <= index)
	{
		if (i == index)
			return (stack);
		i++;
		stack = stack->next;
	}
	return (NULL);
}

// void	ps_stack_print_full(t_stack *stack)
// {
// 	while (stack)
// 	{
// 		if (stack->value)
// 		{
// 			ft_printf("Value: %i\n", stack->value);
// 			ft_printf("Index: %i\n", stack->index);
// 			ft_printf("Sorted index: %i\n", stack->sorted_i);
// 			ft_printf("Cost: %i\n", stack->cost);
// 			ft_printf("Is cheapest?: %i\n", stack->is_cheapest);
// 			ft_printf("Is above median?: %i\n", stack->above_median);
// 			ft_printf("Is above sorted median?: %i\n",
// 					stack->above_sorted_median);
// 			if (stack->target != NULL)
// 				ft_printf("Target's value: %i\n", stack->target->value);
// 			ft_printf("\n");
// 		}
// 		stack = stack->next;
// 	}
// }

// void	ps_stack_print(t_stack *stack)
// {
// 	while (stack)
// 	{
// 		if (stack->value)
// 			ft_printf("%i\n", stack->value);
// 		stack = stack->next;
// 	}
// }
