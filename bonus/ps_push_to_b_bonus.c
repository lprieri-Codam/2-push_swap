/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_push_to_b_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/07 15:20:11 by lprieri       #+#    #+#                 */
/*   Updated: 2024/04/09 13:24:49 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

/* --------------- PROTOTYPES --------------- */

void	ps_set_target_a(t_info *info, t_stack *a, t_stack *b);
t_stack	*ps_find_best_match(t_info *info,
			t_stack *seeker, t_stack **targeted_stack);
void	ps_calculate_costs(t_stack *a, t_stack *b);
t_stack	*ps_set_cheapest(t_info *info, t_stack *stack);
int		ps_check_for_double_stack(t_info *info, t_stack **skip_stack);

/* --------------- FUNCTIONS --------------- */

void	ps_set_target_a(t_info *info, t_stack *a, t_stack *b)
{
	t_stack	*b_copy;

	b_copy = b;
	while (a)
	{
		if (ps_check_for_double_stack(info, &b_copy))
			continue ;
		a->target = ps_find_best_match(info, a, &b);
		a = a->next;
	}
}

t_stack	*ps_find_best_match(t_info *info,
			t_stack *seeker, t_stack **targeted_stack)
{
	int		best_matched_i;
	t_stack	*target_node;
	t_stack	*t_iterator;

	if (!seeker || !*targeted_stack)
		return (NULL);
	best_matched_i = -1;
	target_node = NULL;
	t_iterator = *targeted_stack;
	while (t_iterator)
	{
		if (ps_check_for_double_stack(info, &t_iterator))
			continue ;
		if (t_iterator->sorted_i < seeker->sorted_i
			&& t_iterator->sorted_i > best_matched_i)
		{
			best_matched_i = t_iterator->sorted_i;
			target_node = t_iterator;
		}
		t_iterator = t_iterator->next;
	}
	if (best_matched_i == -1)
		target_node = find_max(info, *targeted_stack);
	return (target_node);
}

int	ps_check_for_double_stack(t_info *info, t_stack **skip_stack)
{
	if (info->second_stack
		&& is_in_x_to_y(*skip_stack, info->upper_node, info->lower_node))
	{
		set_first_stack(info->upper_node, info->lower_node);
		skip_from_x_to_y(skip_stack, info->lower_node);
		return (1);
	}
	return (0);
}

void	ps_calculate_costs(t_stack *a, t_stack *b)
{
	int	nodes_a;
	int	nodes_b;

	nodes_a = ps_count_nodes(a);
	nodes_b = ps_count_nodes(b);
	ps_indices_init(a);
	ps_indices_init(b);
	while (a)
	{
		a->cost = nodes_a - a->index;
		if (a->above_median)
			a->cost = a->index;
		if (a->target->above_median)
			a->cost += a->target->index;
		else
			a->cost += nodes_b - a->target->index;
		a = a->next;
	}
}

t_stack	*ps_set_cheapest(t_info *info, t_stack *stack)
{
	int		cheapest_cost;
	t_stack	*cheapest_node;

	if (!stack)
		return (NULL);
	cheapest_cost = stack->cost;
	cheapest_node = stack;
	while (stack)
	{
		if (info->second_stack
			&& is_in_x_to_y(stack, info->upper_node, info->lower_node))
		{
			skip_from_x_to_y(&stack, info->lower_node);
			continue ;
		}
		if (stack->cost < cheapest_cost)
		{
			cheapest_cost = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->is_cheapest = true;
	return (cheapest_node);
}
