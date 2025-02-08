/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:57:52 by achemlal          #+#    #+#             */
/*   Updated: 2025/02/08 19:04:19 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_max_index(t_stack *stack_b)
{
	t_stack	*temp;
	int		max;
	int		max_i;
	int		i;

	temp = stack_b;
	max = stack_b->data;
	max_i = 0;
	i = 0;
	while (temp)
	{
		if (temp->data > max)
		{
			max = temp->data;
			max_i = i;
		}
		temp = temp->next;
		i++;
	}
	return (max_i);
}

void	move_max_to_top(t_stack **stack_b, int max_i)
{
	int	size;
	int	i;

	size = size_stack(*stack_b);
	i = 0;
	if (max_i <= size / 2)
	{
		while (i++ < max_i)
			rb(stack_b);
	}
	else
	{
		while (i++ < size - max_i)
			rrb(stack_b);
	}
}

void	push_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int	max_i;

	while (*stack_b)
	{
		max_i = find_max_index(*stack_b);
		move_max_to_top(stack_b, max_i);
		pa(stack_a, stack_b);
	}
}
