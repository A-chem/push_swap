# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>


typedef struct s_data
{
    char    *str;
    char    **num;
}           t_data;

typedef struct s_stack
{
    int             data;
    size_t          index;
    struct s_stack  *next;
}                   t_stack;

int     input_valid(t_data *data);
int     ft_atoi(char *str);
int     ft_isdigit(int c);
size_t  ft_strlen(char *s);
char    **ft_split(char *s, char c);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
t_stack *ft_stack_new(int data , size_t index);
void    ft_stack_add_front(t_stack **node, t_stack *new);
t_stack *init_stack(t_stack **stack, t_data *data);
void    sa(t_stack **stack_a);
void    free_data(t_data *data);
void    free_double_(char **str);
void    free_stack(t_stack **stack);
void    sa(t_stack **stack_a);
void    sb(t_stack **stack_b);
void    ss(t_stack **stack_a, t_stack **stack_b);
void    pa(t_stack **stack_a, t_stack **stack_b);
void    pb(t_stack **stack_a, t_stack **stack_b);
void    ra(t_stack **stack_a);
void    rb(t_stack **stack_b);
void    ra(t_stack **stack_a);
void    rb(t_stack **stack_b);
void    rr(t_stack **stack_a, t_stack **stack_b);
void    rra(t_stack **stack_a);
void    rrb(t_stack **stack_b);
void    rrr(t_stack **stack_a, t_stack **stack_b);
void    sort_two(t_stack **stack_a);
void    sort_three(t_stack **stack_a);
size_t  size_stack(t_stack *stack);
void    sort_stack(t_stack **stack_a , t_stack **stack_b);
void    print_stack(t_stack *stack, char *name);
int min_stack (t_stack *stack);
int max_stack (t_stack *stack);
#endif