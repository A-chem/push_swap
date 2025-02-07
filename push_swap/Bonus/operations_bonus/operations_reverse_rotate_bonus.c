// operations_reverse_rotate.c: Implement rra, rrb, and rrr.
#include "../include/checker_bonus.h"
void rra(t_stack **stack_a)
{
    t_stack *temp = *stack_a;
    t_stack *last = *stack_a;
    if (!*stack_a || !(*stack_a)->next)
    return;
    while (last->next)
    last = last->next;
    while (temp->next != last)
    temp = temp->next;
    temp->next = NULL;
    last->next = *stack_a;
    *stack_a = last;
}
void rrb(t_stack **stack_b)
{
    t_stack *temp = *stack_b;
    t_stack *last = *stack_b;
    if (!*stack_b || !(*stack_b)->next)
    return;
    while (last->next)
    last = last->next;
    while (temp->next != last)
    temp = temp->next;
    temp->next = NULL;
    last->next = *stack_b;
    *stack_b = last;
}
void rrr(t_stack **stack_a, t_stack **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}