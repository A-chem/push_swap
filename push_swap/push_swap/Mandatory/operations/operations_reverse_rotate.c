/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:31:15 by achemlal          #+#    #+#             */
/*   Updated: 2025/02/08 17:36:23 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *stack_a;
	last = *stack_a;
	if (!*stack_a || !(*stack_a)->next)
		return ;
	while (last->next)
		last = last->next;
	while (temp->next != last)
		temp = temp->next;
	temp->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	write (1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *stack_b;
	last = *stack_b;
	if (!*stack_b || !(*stack_b)->next)
		return ;
	while (last->next)
		last = last->next;
	while (temp->next != last)
		temp = temp->next;
	temp->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	write (1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write (1, "rrr\n", 4);
}
