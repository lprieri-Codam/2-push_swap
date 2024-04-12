/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_presort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lisandro <lisandro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/07 01:30:53 by lisandro      #+#    #+#                 */
/*   Updated: 2024/04/12 11:56:35 by lisandro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* --------------- PROTOTYPES --------------- */

int			ps_presort(t_info *info, t_stack *a);
static int	ps_create_array(t_stack *a, int **arr, int nodes_nbr);
static void	ps_bubblesort(int *arr, int nodes_nbr);

/* --------------- FUNCTIONS --------------- */

/*	PRESORT
*	Takes a stack 'A' and pre-sorts its elements with bubblesort.
*	Each node in the stack gets assigned their respective sorted index.
*/
int	ps_presort(t_info *info, t_stack *a)
{
	int	*arr;
	int	i;
	int	median;

	if (!ps_create_array(a, &arr, info->nodes_nbr))
		return (0);
	median = info->nodes_nbr / 2;
	ps_bubblesort(arr, info->nodes_nbr);
	while (a)
	{
		i = 0;
		while (i < info->nodes_nbr)
		{
			if (a->value == arr[i])
			{
				a->sorted_i = i;
				if (i <= median)
					a->above_sorted_median = true;
				break ;
			}
			i++;
		}
		a = a->next;
	}
	return (free(arr), 1);
}

/*	CREATE ARRAY
*	Used in the presorting function to make an array for bubblesort
*	out of the elements from the stack 'A'.
*	The array only contains the values of each node.
*/
static int	ps_create_array(t_stack *a, int **arr, int nodes_nbr)
{
	t_stack	*current;
	int		i;

	*arr = (int *) malloc(sizeof(int) * nodes_nbr);
	if (!*arr)
		return (*arr = NULL, 0);
	current = a;
	i = 0;
	while (current)
	{
		(*arr)[i] = current->value;
		current = current->next;
		i++;
	}
	return (1);
}

/*	BUBBLESORT
*	Iterates through the elements of an array,
*	swapping the current element with the next one
*	if the current value is bigger than the next.
*/
static void	ps_bubblesort(int *arr, int nodes_nbr)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < nodes_nbr - 1)
	{
		j = 0;
		while (j < nodes_nbr - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
