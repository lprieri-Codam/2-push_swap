/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_push_swap.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/09 11:54:37 by lprieri       #+#    #+#                 */
/*   Updated: 2024/04/09 12:36:11 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* --------------- PROTOTYPES --------------- */

/* --------------- FUNCTIONS --------------- */

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	t_info	*info;

	a = NULL;
	b = NULL;
	info = NULL;
	if (!ps_parse(&info, &a, argc, argv))
		return (ps_stack_clear(&a), 1);
	ps_vurksort(&info, &a, &b);
	ps_stack_clear(&a);
	ps_stack_clear(&b);
	free(info);
}
