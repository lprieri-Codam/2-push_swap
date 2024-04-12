/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_info.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lisandro <lisandro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/07 01:25:28 by lisandro      #+#    #+#                 */
/*   Updated: 2024/04/10 13:55:41 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* --------------- PROTOTYPES --------------- */

int	ps_info_init(t_info **info, t_stack *a);

/* --------------- FUNCTIONS --------------- */

/*	PS_INFO_INIT
*	Assigns heap memory to the address of an info pointer passed as arg.
*	Then it initializes the variables inside the info structure.
*/
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
