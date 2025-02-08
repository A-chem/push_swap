/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:13:59 by achemlal          #+#    #+#             */
/*   Updated: 2025/02/08 20:57:59 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

static int	validate_input(int ac, char **av, t_data *data)
{
	int		i;
	char	*temp;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			return (0);
		temp = data->str;
		data->str = ft_strjoin(data->str, av[i]);
		free(temp);
		temp = data->str;
		data->str = ft_strjoin(data->str, " ");
		free(temp);
		i++;
	}
	if (!input_valid(data))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_data	data;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	if (!validate_input(ac, av, &data))
	{
		write(2, "Error\n", 6);
		return (free_data(&data), 0);
	}
	stack_a = init_stack(&stack_a, &data);
	read_and_execute(&stack_a, &stack_b);
	while (stack_a)
		stack_a = stack_a->next;
	free_data(&data);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
