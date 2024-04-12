/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_push_swap_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lprieri <lprieri@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/09 11:54:37 by lprieri       #+#    #+#                 */
/*   Updated: 2024/04/09 14:42:03 by lprieri       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

/* --------------- PROTOTYPES --------------- */

static int	ps_run_instruction(char *instruction,
				t_info **info, t_stack **a, t_stack **b);

/* --------------- FUNCTIONS --------------- */

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	t_info	*info;
	char	*line;

	a = NULL;
	b = NULL;
	info = NULL;
	if (!ps_parse(&info, &a, argc, argv))
		return (ps_stack_clear(&a), 1);
	line = get_next_line(0);
	while (line != NULL)
	{
		if (!ps_run_instruction(line, &info, &a, &b))
			return (ft_putstr_fd("Error\n", 2), free(line), free(info),
				ps_stack_clear(&a), ps_stack_clear(&a), 1);
		ps_free((void **) &line);
		line = get_next_line(0);
	}
	if (ps_is_sorted(a) == 1)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	(ps_stack_clear(&a), ps_stack_clear(&b));
	free(info);
}

static int	ps_run_instruction(char *instruction,
				t_info **info, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(instruction, "sa\n", ft_strlen(instruction)))
		return (sa(info, a), 1);
	else if (!ft_strncmp(instruction, "sb\n", ft_strlen(instruction)))
		return (sb(info, b), 1);
	else if (!ft_strncmp(instruction, "ss\n", ft_strlen(instruction)))
		return (ss(info, a, b), 1);
	else if (!ft_strncmp(instruction, "pa\n", ft_strlen(instruction)))
		return (pa(info, a, b), 1);
	else if (!ft_strncmp(instruction, "pb\n", ft_strlen(instruction)))
		return (pb(info, a, b), 1);
	else if (!ft_strncmp(instruction, "ra\n", ft_strlen(instruction)))
		return (ra(info, a), 1);
	else if (!ft_strncmp(instruction, "rb\n", ft_strlen(instruction)))
		return (rb(info, b), 1);
	else if (!ft_strncmp(instruction, "rr\n", ft_strlen(instruction)))
		return (rr(info, a, b), 1);
	else if (!ft_strncmp(instruction, "rra\n", ft_strlen(instruction)))
		return (rra(info, a), 1);
	else if (!ft_strncmp(instruction, "rrb\n", ft_strlen(instruction)))
		return (rrb(info, b), 1);
	else if (!ft_strncmp(instruction, "rrr\n", ft_strlen(instruction)))
		return (rrr(info, a, b), 1);
	return (0);
}
