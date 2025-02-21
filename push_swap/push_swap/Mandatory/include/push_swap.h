/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achemlal <achemlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:27:44 by achemlal          #+#    #+#             */
/*   Updated: 2025/02/21 14:24:58 by achemlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

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
typedef struct s_element
{
	int	size_a;
	int	size_b;
	int	*array;
	int	chunk_size;
}		t_element;

int		input_valid(t_data *data);
int		ft_atoi(char *str);
long	ft_atoi_long(const char *str);
int		ft_isdigit(int c);
size_t	ft_strlen(char *s);
char	**ft_split(char *s, char c);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char *s1, char *set);
t_stack	*ft_stack_new(int data, size_t index);
void	ft_stack_add_front(t_stack **node, t_stack *new);
t_stack	*init_stack(t_stack **stack, t_data *data);
void	sa(t_stack **stack_a);
void	free_data(t_data *data);
void	free_double_(char **str);
void	free_stack(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack *stack);
void	sort_two(t_stack **stack_a);
void	sort_three(t_stack **stack_a);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort_chunk(t_stack **stack_a, t_stack **stack_b, t_element *element);
int		size_stack(t_stack *stack);
int		*stack_array(t_stack *stack, int size);
int		find_index_in_array( int *array, int size, int data);
void	move_element(t_stack **stack_a, t_stack **stack_b, int a_index, \
		t_element *element);
int		detect_comb(t_stack **stack_a, t_element *element);
int		find_min_index(t_stack *stack);
void	move_min_to_top(t_stack **stack, int min_i);
int		find_max_index(t_stack *stack_b);
void	move_max_to_top(t_stack **stack_b, int max_i);
void	push_stack_a(t_stack **stack_a, t_stack **stack_b);
void	print_stack(t_stack *stack, char *name);
void	handle_error(void);

#endif
