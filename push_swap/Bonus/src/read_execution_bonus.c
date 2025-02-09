/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_execution_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:27:04 by achemlal          #+#    #+#             */
/*   Updated: 2025/02/09 12:02:19 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

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

static void	execute_3_char_command(char *cmd, \
		t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(cmd, "sa\n", 2) == 0)
		sa(stack_a);
	else if (ft_strncmp(cmd, "sb\n", 2) == 0)
		sb(stack_b);
	else if (ft_strncmp(cmd, "ss\n", 2) == 0)
		ss(stack_a, stack_b);
	else if (ft_strncmp(cmd, "pa\n", 2) == 0)
		pa(stack_a, stack_b);
	else if (ft_strncmp(cmd, "pb\n", 2) == 0)
		pb(stack_a, stack_b);
	else if (ft_strncmp(cmd, "ra\n", 2) == 0)
		ra(stack_a);
	else if (ft_strncmp(cmd, "rb\n", 2) == 0)
		rb(stack_b);
	else if (ft_strncmp(cmd, "rr\n", 2) == 0)
		rr(stack_a, stack_b);
}

static void	execute_4_char_command(char *cmd, \
		t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(cmd, "rra\n", 3) == 0)
		rra(stack_a);
	else if (ft_strncmp(cmd, "rrb\n", 3) == 0)
		rrb(stack_b);
	else if (ft_strncmp(cmd, "rrr\n", 3) == 0)
		rrr(stack_a, stack_b);
}

static void	execute_instruction(char *cmd, t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_strlen(cmd);
	if (size == 3)
		execute_3_char_command(cmd, stack_a, stack_b);
	else if (size == 4)
		execute_4_char_command(cmd, stack_a, stack_b);
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	read_and_execute(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		execute_instruction(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(*stack_a) && !(*stack_b))
	{
		write (1, "OK\n", 3);
		free_stack (stack_a);
		free_stack (stack_b);
		exit(0);
	}
	else
	{
		write (1, "KO\n", 3);
		free_stack (stack_a);
		free_stack (stack_b);
		exit(0);
	}
}
