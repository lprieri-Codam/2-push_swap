/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_free_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lisandro <lisandro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/06 19:48:29 by lisandro      #+#    #+#                 */
/*   Updated: 2024/04/09 13:24:38 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

/* --------------- PROTOTYPES --------------- */

void	ps_free(void **content);
void	ps_free_array(void ***array);

/* --------------- FUNCTIONS --------------- */

void	ps_free(void **content)
{
	free(*content);
	*content = NULL;
}

void	ps_free_array(void ***array)
{
	int	i;

	i = 0;
	while ((*array)[i])
	{
		ps_free((void **) &(*array)[i]);
		i++;
	}
	free(*array);
	*array = NULL;
}
