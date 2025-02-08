/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:36:42 by achemlal          #+#    #+#             */
/*   Updated: 2025/02/08 17:40:25 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	write (1, "ra\n", 3);
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
	write (1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write (1, "rr\n", 3);
}
