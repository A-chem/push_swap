/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_execution_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:27:04 by achemlal          #+#    #+#             */
/*   Updated: 2025/02/15 20:56:22 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

char	*read_operations(void)
{
	char	*line;
	char	*str;
	char	*tmp;

	str = ft_strdup("");
	line = get_next_line(0);
	while (line)
	{
		tmp = str;
		str = ft_strjoin(str, line);
		if (!str)
			return (free (tmp), NULL);
		free(tmp);
		free(line);
		line = get_next_line(0);
	}
	if (!str || *str == '\0')
	{
		write(2, "Error\n", 6);
		free(str);
		exit(1);
	}
	return (str);
}

char	**parse_operations(char *str)
{
	char	**opr;

	opr = ft_split(str, '\n');
	free(str);
	if (!opr)
		return (NULL);
	return (opr);
}

void	validate_operations(char **opr)
{
	if (!check_operation(opr))
	{
		write(2, "Error\n", 6);
		free_double_(opr);
		exit(1);
	}
}

void	execute_and_check(t_stack **stack_a, t_stack **stack_b, char **opr)
{
	execute_operation(stack_a, stack_b, opr);
	if (is_sorted(*stack_a) && !(*stack_b))
	{
		write(1, "OK\n", 3);
		free_double_(opr);
		free_stack (stack_a);
		free_stack (stack_b);
		exit (0);
	}
	else
	{
		write(1, "KO\n", 3);
		free_double_(opr);
		free_stack (stack_a);
		free_stack (stack_b);
		exit (0);
	}
}

void	read_and_execute(t_stack **stack_a, t_stack **stack_b)
{
	char	*str;
	char	**opr;

	str = NULL;
	str = read_operations ();
	opr = parse_operations (str);
	validate_operations(opr);
	execute_and_check(stack_a, stack_b, opr);
	free_double_(opr);
	free(str);
}
