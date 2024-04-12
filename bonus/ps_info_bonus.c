/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_info_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lisandro <lisandro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/07 01:25:28 by lisandro      #+#    #+#                 */
/*   Updated: 2024/04/09 13:24:40 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

/* --------------- PROTOTYPES --------------- */

int	ps_info_init(t_info **info, t_stack *a);

/* --------------- FUNCTIONS --------------- */

int	ps_info_init(t_info **info, t_stack *a)
{
	*info = (t_info *) malloc(sizeof(t_info));
	if (!*info)
		return (0);
	(*info)->nodes_nbr = ps_count_nodes(a);
	(*info)->total_cost = 0;
	(*info)->upper_node = NULL;
	(*info)->lower_node = NULL;
	(*info)->second_stack = 0;
	return (1);
}
