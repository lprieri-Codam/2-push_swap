/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_parse.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lisandro <lisandro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/06 19:33:04 by lisandro      #+#    #+#                 */
/*   Updated: 2024/04/12 11:34:25 by lisandro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* --------------- PROTOTYPES --------------- */

int	ps_parse(t_info **info, t_stack **a, int argc, char *argv[]);
int	ps_parse_arg(t_stack **a, char *str);
int	ps_parse_args(t_stack **a, int argc, char *argv[]);
int	ps_has_repetitions(t_stack *stack);

/* --------------- FUNCTIONS --------------- */

/*	PS_PARSE
*	Parses the arguments passed to the program.
*	It converts each number from string to integer type.
*	It checks for repeated values and returns 'Error' if that's the case.
*	It also pre-sorts the stack using bubble-sort
*	and assigns the corresponding sorted index to each value.
*/
int	ps_parse(t_info **info, t_stack **a, int argc, char *argv[])
{
	int	flag;

	flag = 0;
	if (argc < 2)
		return (flag);
	else if (argc == 2)
		flag = ps_parse_arg(a, argv[1]);
	else if (argc > 2)
		flag = ps_parse_args(a, argc, argv);
	if (ps_has_repetitions(*a))
		return (ft_putstr_fd("Error\n", 2), 0);
	if (!flag || !ps_info_init(info, *a))
		return (ft_putstr_fd("Error\n", 2), flag);
	ps_presort(*info, *a);
	return (flag);
}

/*	PS_PARSE_ARG
*	The function takes the second argument of the program.
*	It checks if it is an array containing numbers separated by spaces.
*	Converts the elements of the array into digits if they are.
*	It initializes the 'a' stack, and fills it values.
*	On failing to convert a number or to create a node in the stack
*	it clears frees memory of the stack and returns 0.
*	It returns 1 on success.
*/
int	ps_parse_arg(t_stack **a, char *str)
{
	char	**arr;
	int		i;
	int		number;
	t_stack	*current;

	arr = ft_split(str, ' ');
	if (!arr)
		return (0);
	if (!arr[0])
		return (ps_free_array((void ***) &arr), 0);
	i = 0;
	while (arr[i])
	{
		if (!ps_isdigit(arr[i]))
			return (ps_free_array((void ***) &arr), 0);
		if (ps_atoi(arr[i], &number) == -1)
			return (ps_stack_clear(a), ps_free_array((void ***) &arr), 0);
		ps_stack_init(a, &current, i, number);
		if (!current || number > MAX_INT || number < MIN_INT)
			return (ps_stack_clear(a), ps_free_array((void ***) &arr), 0);
		i++;
	}
	return (ps_free_array((void ***) &arr), 1);
}

/*	PS_PARSE_ARGS
*	Checks if the arguments passed to the program are digits.
*	Converts the arguments into digits if they are.
*	It initializes the 'a' stack, and fills it values.
*	On failing to convert a number or to create a node in the stack
*	it clears frees memory of the stack and returns 0.
*	It returns 1 on success.
*/
int	ps_parse_args(t_stack **a, int argc, char *argv[])
{
	int		i;
	int		number;
	t_stack	*current;

	i = 1;
	while (i < argc)
	{
		if (!ps_isdigit(argv[i]))
			return (0);
		if (ps_atoi(argv[i], &number) == -1)
			return (ps_stack_clear(a), 0);
		ps_stack_init(a, &current, i, number);
		if (!current)
			return (ps_stack_clear(a), 0);
		i++;
	}
	return (1);
}

/*	PS_HAS_REPETITIONS
*	Checkes whether there are repeated values in a stack.
*	Returns 1 if there are, or 0 if there aren't.
*/
int	ps_has_repetitions(t_stack *stack)
{
	t_stack	*comparator;

	while (stack)
	{
		comparator = stack->next;
		while (comparator)
		{
			if (stack->value == comparator->value)
				return (1);
			comparator = comparator->next;
		}
		stack = stack->next;
	}
	return (0);
}
