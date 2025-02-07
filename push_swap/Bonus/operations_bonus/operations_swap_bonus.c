// operations_swap.c: Implement sa, sb, and ss
#include "../include/checker_bonus.h"
void sa(t_stack **stack_a)
{
    t_stack *first;
    t_stack *second;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;
    first = *stack_a;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack_a = second;
}
void sb(t_stack **stack_b)
{
    t_stack *first;
    t_stack *second;

    if (*stack_b == NULL || (*stack_b)->next == NULL)
        return;
    first = *stack_b;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack_b = second;
}
void ss(t_stack **stack_a, t_stack **stack_b)
{
    sa(stack_a);
    sb(stack_b);
}
