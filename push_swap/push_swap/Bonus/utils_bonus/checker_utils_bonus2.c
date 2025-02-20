/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 21:03:38 by achemlal          #+#    #+#             */
/*   Updated: 2025/02/15 21:03:39 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

static void	execute_two_char_operation(t_stack **stack_a, \
			t_stack **stack_b, char *opr)
{
	if (ft_strncmp(opr, "pa", 2) == 0)
		pa(stack_a, stack_b);
	else if (ft_strncmp(opr, "pb", 2) == 0)
		pb(stack_a, stack_b);
	else if (ft_strncmp(opr, "ra", 2) == 0)
		ra(stack_a);
	else if (ft_strncmp(opr, "rb", 2) == 0)
		rb(stack_b);
	else if (ft_strncmp(opr, "rr", 2) == 0)
		rr(stack_a, stack_b);
	else if (ft_strncmp(opr, "sa", 2) == 0)
		sa(stack_a);
	else if (ft_strncmp(opr, "sb", 2) == 0)
		sb(stack_b);
	else if (ft_strncmp(opr, "ss", 2) == 0)
		ss(stack_a, stack_b);
}

static void	execute_three_char_operation(t_stack **stack_a, \
			t_stack **stack_b, char *opr)
{
	if (ft_strncmp(opr, "rra", 3) == 0)
		rra(stack_a);
	else if (ft_strncmp(opr, "rrb", 3) == 0)
		rrb(stack_b);
	else if (ft_strncmp(opr, "rrr", 3) == 0)
		rrr(stack_a, stack_b);
}

void	execute_operation(t_stack **stack_a, t_stack **stack_b, char **opr)
{
	int	i;
	int	size;

	i = 0;
	while (opr[i])
	{
		size = ft_strlen(opr[i]);
		if (size == 2)
			execute_two_char_operation(stack_a, stack_b, opr[i]);
		else if (size == 3)
			execute_three_char_operation(stack_a, stack_b, opr[i]);
		i++;
	}
}
