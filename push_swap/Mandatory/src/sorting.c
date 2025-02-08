/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:10:20 by achemlal          #+#    #+#             */
/*   Updated: 2025/02/08 18:27:48 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a);
}

void	sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->data;
	b = (*stack_a)->next->data;
	c = (*stack_a)->next->next->data;
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	min_index;

	min_index = find_min_index(*stack_a);
	move_min_to_top(stack_a, min_index);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min_index;

	min_index = find_min_index(*stack_a);
	move_min_to_top(stack_a, min_index);
	pb(stack_a, stack_b);
	min_index = find_min_index(*stack_a);
	move_min_to_top(stack_a, min_index);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_chunk(t_stack **stack_a, t_stack **stack_b, t_element *element)
{
	int	a_index;
	int	*array;

	element->size_a = size_stack(*stack_a);
	array = stack_array(*stack_a, element->size_a);
	element->array = array;
	if (!array)
		return ;
	element->size_b = 0;
	while (*stack_a)
	{
		a_index = find_index_in_array(array, element->size_a, (*stack_a)->data);
		move_element(stack_a, stack_b, a_index, element);
	}
	push_stack_a(stack_a, stack_b);
	free(array);
}
