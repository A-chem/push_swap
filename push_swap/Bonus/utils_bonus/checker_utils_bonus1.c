/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 21:03:29 by achemlal          #+#    #+#             */
/*   Updated: 2025/02/15 21:03:30 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	check_3_char_operation(char *opr)
{
	if (ft_strncmp(opr, "sa", 2) == 0 || ft_strncmp(opr, "sb", 2) == 0
		||ft_strncmp(opr, "ss", 2) == 0 || ft_strncmp(opr, "pa", 2) == 0
		||ft_strncmp(opr, "pb", 2) == 0 || ft_strncmp(opr, "ra", 2) == 0
		||ft_strncmp(opr, "rb", 2) == 0 || ft_strncmp(opr, "rr", 2) == 0)
		return (1);
	return (0);
}

static int	check_4_char_operation(char *opr)
{
	if (ft_strncmp(opr, "rra", 3) == 0 || ft_strncmp(opr, "rrb", 3) == 0
		||ft_strncmp(opr, "rrr", 3) == 0)
		return (1);
	return (0);
}

int	check_operation(char **opr)
{
	int	i;
	int	size;

	i = 0;
	while (opr[i])
	{
		size = ft_strlen(opr[i]);
		if (size == 2)
		{
			if (check_3_char_operation(opr[i]) == 0)
				return (0);
		}
		else if (size == 3)
		{
			if (!check_4_char_operation(opr[i]))
				return (0);
		}
		else
			return (0);
		i++;
	}
	return (1);
}
