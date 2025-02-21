/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:13:59 by achemlal          #+#    #+#             */
/*   Updated: 2025/02/21 14:38:38 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

int	validate_input(int ac, char **av, t_data *data)
{
	int		i;
	char	*temp;
	char	*trimmed;

	i = 1;
	data->str = NULL;
	while (i < ac)
	{
		trimmed = ft_strtrim(av[i], " ");
		if (!trimmed || !trimmed[0])
			return (free (trimmed), free (data->str), handle_error(), 0);
		free(trimmed);
		temp = data->str;
		data->str = ft_strjoin(data->str, av[i]);
		if (!data->str)
			return (free (temp), handle_error(), 0);
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
		handle_error ();
	stack_a = init_stack(&stack_a, &data);
	read_and_execute(&stack_a, &stack_b);
	free_data(&data);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
