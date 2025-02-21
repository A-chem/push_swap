/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:37:52 by achemlal          #+#    #+#             */
/*   Updated: 2025/02/21 14:24:25 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

void	free_double_(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_data(t_data *data)
{
	if (data->str)
		free(data->str);
	if (data->num)
		free_double_(data->num);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	temp = NULL;
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
		temp = NULL;
	}
	stack = NULL;
}

void	handle_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
