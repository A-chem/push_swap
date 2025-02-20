/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:08:05 by achemlal          #+#    #+#             */
/*   Updated: 2025/02/08 20:10:31 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

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
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
