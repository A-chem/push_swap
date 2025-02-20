/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:10:41 by achemlal          #+#    #+#             */
/*   Updated: 2025/02/08 20:11:38 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

void	ra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *stack_a;
	last = *stack_a;
	if (!*stack_a || !(*stack_a)->next)
		return ;
	while (last->next)
		last = last->next;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	last->next = temp;
}

void	rb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *stack_b;
	last = *stack_b;
	if (!*stack_b || !(*stack_b)->next)
		return ;
	while (last->next)
		last = last->next;
	*stack_b = (*stack_b)->next;
	temp->next = NULL;
	last->next = temp;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
