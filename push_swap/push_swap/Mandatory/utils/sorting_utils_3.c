/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:04:31 by achemlal          #+#    #+#             */
/*   Updated: 2025/02/16 14:09:15 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

int	detect_comb(t_stack **stack_a, t_element *element)
{
	t_stack	*tmp;
	int		diff;
	int		count;

	tmp = *stack_a;
	count = 0;
	while (tmp && tmp->next)
	{
		diff = find_index_in_array (element->array, element->size_a, tmp->data)
			- find_index_in_array (element->array, \
					element->size_a, tmp->next->data);
		if (diff == 2 || diff == 3 || diff == 4)
			count++;
		tmp = tmp->next;
	}
	if (count * 10 >= element->size_a * 6)
		return (1);
	return (0);
}

int	find_min_index(t_stack *stack)
{
	int		min;
	int		min_i;
	int		i;

	min = stack->data;
	min_i = 0;
	i = 0;
	while (stack)
	{
		if (stack->data < min)
		{
			min = stack->data;
			min_i = i;
		}
		stack = stack->next;
		i++;
	}
	return (min_i);
}

void	move_min_to_top(t_stack **stack, int min_i)
{
	int	size;
	int	i;

	size = size_stack(*stack);
	i = 0;
	if (min_i <= size / 2)
	{
		while (i++ < min_i)
			ra(stack);
	}
	else
	{
		while (i++ < size - min_i)
			rra(stack);
	}
}
