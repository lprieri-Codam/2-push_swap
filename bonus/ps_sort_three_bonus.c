/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_sort_three_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/07 13:41:31 by lprieri       #+#    #+#                 */
/*   Updated: 2024/04/09 13:24:52 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

/* --------------- PROTOTYPES --------------- */

void	ps_sort_three(t_info **info, t_stack **a);

/* --------------- FUNCTIONS --------------- */

/* Sorts a stack of three nodes into ascending order. */
void	ps_sort_three(t_info **info, t_stack **a)
{
	int	first;
	int	second;
	int	third;

	if (!*a || ps_count_nodes(*a) != 3 || ps_is_sorted(*a) == 1)
		return ;
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first < second && first < third && second > third)
		return (sa(info, a), ps_sort_three(info, a));
	if (first > second && first > third && second > third)
		return (ra(info, a), ps_sort_three(info, a));
	if (first > second && first < third && second < third)
		sa(info, a);
	if (first < second && first > third && second > third)
		rra(info, a);
	if (first > second && first > third && second < third)
		ra(info, a);
}
