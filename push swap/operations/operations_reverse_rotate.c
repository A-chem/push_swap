// operations_reverse_rotate.c: Implement rra, rrb, and rrr.
#include "../include/push_swap.h"
void rra(t_stack **stack_a)
{
    t_stack *temp = *stack_a;
    t_stack *last = *stack_a;
    while (last->next)
    last = last->next;
    while (temp->next != last)
    temp = temp->next;
    temp->next = NULL;
    last->next = *stack_a;
    *stack_a = last;
    printf("rra\n");
}
void rrb(t_stack **stack_b)
{
    t_stack *temp = *stack_b;
    t_stack *last = *stack_b;
    while (last->next)
    last = last->next;
    while (temp->next != last)
    temp = temp->next;
    temp->next = NULL;
    last->next = *stack_b;
    *stack_b = last;
    printf("rrb\n");
}
void rrr(t_stack **stack_a, t_stack **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
    printf("rrr\n");
}