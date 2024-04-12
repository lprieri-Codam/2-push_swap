/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_utils_bonus.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lisandro <lisandro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/06 19:50:46 by lisandro      #+#    #+#                 */
/*   Updated: 2024/04/09 13:24:58 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

/* --------------- PROTOTYPES --------------- */

int	ps_isdigit(char *arg);
int	ps_is_sorted(t_stack *stack);

/* --------------- FUNCTIONS --------------- */

int	ps_isdigit(char *arg)
{
	int	i;

	i = 0;
	while (arg && arg[i])
	{
		if (i == 0 && arg[i] == '-')
			i++;
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
*	Returns 0 if it is not sorted.
*	Returns -1 if it is sorted in descending order.
*	Returns 1 if it is sorted in ascending order.
*/
int	ps_is_sorted(t_stack *stack)
{
	int		prev_value;
	int		curr_value;
	int		flags[2];

	if (!stack)
		return (0);
	prev_value = stack->value;
	flags[0] = 0;
	flags[1] = 0;
	while (stack)
	{
		curr_value = stack->value;
		if (prev_value > curr_value)
			flags[0] = 1;
		if (prev_value < curr_value)
			flags[1] = 1;
		stack = stack->next;
		prev_value = curr_value;
	}
	if ((flags[0] == 1 && flags[1] == 1) || (flags[0] == 0 && flags[1] == 0))
		return (0);
	else if (flags[0] == 1 && flags[1] == 0)
		return (-1);
	else
		return (1);
}

int	ps_atoi(const char *str, int *number)
{
	int			i;
	long long	nbr;
	int			is_negative;

	i = 0;
	nbr = 0;
	is_negative = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_negative = 1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	if (nbr > MAX_INT || nbr < MIN_INT)
		return (-1);
	if (is_negative)
		return (*number = (int) -nbr, 1);
	return (*number = (int) nbr, 1);
}
