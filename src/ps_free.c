/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_free.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lisandro <lisandro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/06 19:48:29 by lisandro      #+#    #+#                 */
/*   Updated: 2024/04/10 13:53:43 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* --------------- PROTOTYPES --------------- */

void	ps_free(void **content);
void	ps_free_array(void ***array);

/* --------------- FUNCTIONS --------------- */

/*	PS_FREE
*	Frees a variable and sets it to NULL (to avoid dangling pointers).
*/
void	ps_free(void **content)
{
	free(*content);
	*content = NULL;
}

/*	PS_FREE_ARRAY
*	Frees every element of the array.
*	Then it frees the array itself and sets the pointer to NULL.
*/
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
