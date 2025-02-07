// operations_rotate.c: Implement ra, rb, and rr
#include "../include/checker_bonus.h"
void ra(t_stack **stack_a)
{
    t_stack *temp = *stack_a;
    t_stack *last = *stack_a;
       if (!*stack_a || !(*stack_a)->next)
            return;
    while (last->next)
    last = last->next;
    *stack_a = (*stack_a)->next;
    temp->next = NULL;
    last->next = temp;
}
void rb(t_stack **stack_b)
{
    t_stack *temp = *stack_b;
    t_stack *last = *stack_b;
    if (!*stack_b || !(*stack_b)->next)
    return;
    while (last->next)
    last = last->next;
    *stack_b = (*stack_b)->next;
    temp->next = NULL;
    last->next = temp;
}
void rr(t_stack **stack_a, t_stack **stack_b)
{
    ra(stack_a);
    rb(stack_b);
}
