/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:52:32 by achemlal          #+#    #+#             */
/*   Updated: 2025/02/08 17:58:37 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_duplicate(char **num, char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (num[i])
	{
		if (ft_atoi(num[i]) == ft_atoi(str))
			count++;
		i++;
	}
	if (count > 1)
		return (0);
	return (1);
}

int	valid_number(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	if ((str[i] == '-' || str[i] == '+' ) && str[i + 1] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	input_valid(t_data *data)
{
	int	i;
	int	j;

	data->num = ft_split(data ->str, ' ');
	if (!data->num)
		return (0);
	i = 0;
	j = 0;
	while (data->num[i])
	{
		if (!valid_number(data->num[i]))
			return (0);
		else if (ft_atoi_long(data->num[i]) > INT_MAX
			|| ft_atoi_long(data->num[i]) < INT_MIN)
			return (0);
		else if (ft_duplicate(data->num, data->num[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
