/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:49:09 by achemlal          #+#    #+#             */
/*   Updated: 2025/02/21 13:51:22 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	size_stack(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

int	*sort_array(int *array, int size)
{
	int	temp;
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (array[i] > array[i + 1])
		{
			temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	return (array);
}

int	*stack_array(t_stack *stack, int size)
{
	int	*array;
	int	i;

	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	i = 0;
	while (stack)
	{
		array[i] = stack->data;
		stack = stack->next;
		i++;
	}
	array = sort_array(array, size);
	return (array);
}

int	find_index_in_array(int *array, int size, int data)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == data)
			return (i);
		i++;
	}
	return (-1);
}

void	move_element(t_stack **stack_a, t_stack **stack_b, \
		int a_index, t_element *element)
{
	if (a_index <= element->size_b)
	{
		pb(stack_a, stack_b);
		element->size_b++;
	}
	else if (a_index <= element->size_b + element->chunk_size)
	{
		pb(stack_a, stack_b);
		rb(stack_b);
		element->size_b++;
	}
	else if (detect_comb(stack_a, element))
		rra(stack_a);
	else
	{
		ra(stack_a);
	}
}
