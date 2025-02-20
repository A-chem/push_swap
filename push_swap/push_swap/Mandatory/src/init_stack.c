/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:44:19 by achemlal          #+#    #+#             */
/*   Updated: 2025/02/16 09:29:15 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*create_node(int value, size_t index)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = value;
	new_node->index = index;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*insert_node(t_stack *stack, int value, size_t index)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = create_node(value, index);
	if (!new_node)
		return (NULL);
	if (!stack)
		return (new_node);
	else
	{
		current = stack;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
	return (stack);
}

t_stack	*init_stack(t_stack **stack, t_data *data)
{
	int	i;

	i = 0;
	while (data->num[i])
	{
		*stack = insert_node(*stack, ft_atoi(data->num[i]), i);
		if (!*stack)
		{
			free_data(data);
			return (NULL);
		}
		i++;
	}
	return (*stack);
}
