/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_double_stack_utils_bonus.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lisandro <lisandro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/06 16:12:37 by lisandro      #+#    #+#                 */
/*   Updated: 2024/04/09 13:24:31 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

/* --------------- PROTOTYPES --------------- */

int		count_from_x_to_y(t_stack *x, t_stack *y);
int		is_in_x_to_y(t_stack *q, t_stack *x, t_stack *y);
t_stack	*skip_from_x_to_y(t_stack **x, t_stack *y);
void	set_first_stack(t_stack *x, t_stack *y);
void	apply_cost_from_x_to_y(t_info *info, t_stack **x, t_stack *y);

/* --------------- FUNCTIONS --------------- */

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
		return ;
	}
	return ;
}

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
		return ;
	}
	return ;
}
