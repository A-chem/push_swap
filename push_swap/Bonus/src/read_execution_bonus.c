#include "../include/checker_bonus.h"
int is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->data > stack->next->data)
            return (0);
        stack = stack->next;
    }
    return (1);
}
static void execute_instruction(char *cmd, t_stack **stack_a, t_stack **stack_b)
{
    if (ft_strncmp(cmd, "sa" , 2) == 0)
        sa(stack_a);
    else if (ft_strncmp(cmd, "sb" , 2) == 0)
        sb(stack_b);
    else if (ft_strncmp(cmd, "ss" , 2) == 0)
        ss(stack_a , stack_b);
    else if (ft_strncmp(cmd, "pa" , 2) == 0)
        pa( stack_a, stack_b);
    else if (ft_strncmp(cmd, "pb" , 2) == 0)
        pb(stack_a, stack_b);
    else if (ft_strncmp(cmd, "ra" , 2) == 0)
        ra( stack_a);
    else if (ft_strncmp(cmd, "rb" , 2) == 0)
        rb( stack_b);
    else if (ft_strncmp(cmd, "rr" , 2) == 0)
        rr( stack_a, stack_b);
    else if (ft_strncmp(cmd, "rra" , 3) == 0)
        rra( stack_a);
    else if (ft_strncmp(cmd, "rrb" , 3) == 0)
        rrb( stack_b);
    else if (ft_strncmp(cmd, "rrr" , 3) == 0)
        rrr(stack_a, stack_b);
    else
    {
        write(2, "Error\n", 6);
        exit(1);
    }
}
void read_and_execute(t_stack **a, t_stack **b)
{
    char *line;

    while ((line = get_next_line(0)))
    {
        execute_instruction(line, a, b);
        free(line);
    }
    if (is_sorted(*a) && !(*b))
        write (1, "OK\n", 3);
    else
        write (1, "KO\n", 3);
}