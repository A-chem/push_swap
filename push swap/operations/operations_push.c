// operations_push.c: Implement pa and pb.
#include "../include/push_swap.h"

void pa(t_stack **stack_a, t_stack **stack_b)
{
    if (*stack_b)
    {
        t_stack *temp = *stack_b;
        *stack_b = (*stack_b)->next;
        temp->next = *stack_a;
        *stack_a = temp;
    }
    printf("pa\n");
}
void pb(t_stack **stack_a, t_stack **stack_b)
{
    if (*stack_a)
    {
        t_stack *temp = *stack_a;
        *stack_a = (*stack_a)->next;
        temp->next = *stack_b;
        *stack_b = temp;
    }
    printf("pb\n");
}