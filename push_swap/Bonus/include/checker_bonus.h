/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:46:11 by achemlal          #+#    #+#             */
/*   Updated: 2025/02/08 19:52:35 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "get_next_line.h"

typedef struct s_data
{
	char	*str;
	char	**num;
}			t_data;
typedef struct s_stack
{
	int				data;
	size_t			index;
	struct s_stack	*next;
}					t_stack;

int		input_valid(t_data *data);
int		is_sorted(t_stack *stack);
void	read_and_execute(t_stack **a, t_stack **b);
t_stack	*create_node(int value, size_t index);
t_stack	*insert_node(t_stack *stack, int value, size_t index);
t_stack	*init_stack(t_stack **stack, t_data *data);
int		ft_atoi(char *str);
long	ft_atoi_long(const char *str);
int		ft_isdigit(int c);
size_t	ft_strlen(char *s);
char	**ft_split(char *s, char c);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	free_double_(char **str);
void	free_data(t_data *data);
void	free_stack(t_stack **stack);

#endif
