/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:06:39 by achemlal          #+#    #+#             */
/*   Updated: 2025/02/08 20:07:50 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_b)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = *stack_a;
		*stack_a = temp;
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_a)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = *stack_b;
		*stack_b = temp;
	}
}
