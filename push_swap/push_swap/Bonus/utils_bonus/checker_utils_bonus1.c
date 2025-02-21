/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 21:03:29 by achemlal          #+#    #+#             */
/*   Updated: 2025/02/21 11:32:00 by achemlal         ###   ########.fr       */
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
	if (ft_strncmp(opr, "sa\n", 3) == 0 || ft_strncmp(opr, "sb\n", 3) == 0
		||ft_strncmp(opr, "ss\n", 3) == 0 || ft_strncmp(opr, "pa\n", 3) == 0
		||ft_strncmp(opr, "pb\n", 3) == 0 || ft_strncmp(opr, "ra\n", 3) == 0
		||ft_strncmp(opr, "rb\n", 3) == 0 || ft_strncmp(opr, "rr\n", 3) == 0)
		return (1);
	return (0);
}

static int	check_4_char_operation(char *opr)
{
	if (ft_strncmp(opr, "rra\n", 4) == 0 || ft_strncmp(opr, "rrb\n", 4) == 0
		||ft_strncmp(opr, "rrr\n", 4) == 0)
		return (1);
	return (0);
}

int	check_operation(char *opr)
{
	int	size;

	size = ft_strlen(opr);
	if (size == 3)
	{
		if (check_3_char_operation(opr) == 0)
			return (0);
	}
	else if (size == 4)
	{
		if (!check_4_char_operation(opr))
			return (0);
	}
	else
		return (0);
	return (1);
}
