#include "../include/push_swap.h"
int find_max_index(t_stack *stack_b)
{
    int max = stack_b->data;
    int max_i = 0;
    int i = 0;
    t_stack *temp = stack_b;

    while (temp)
    {
        if (temp->data > max)
        {
            max = temp->data;
            max_i = i;
        }
        temp = temp->next;
        i++;
    }
    return max_i;
}
void move_max_to_top(t_stack **stack_b, int max_i)
{
    int size = size_stack(*stack_b);
    int i = 0;

    if (max_i <= size / 2)
    {
        while (i++ < max_i)
            rb(stack_b);
    }
    else
    {
        while (i++ < size - max_i)
            rrb(stack_b);
    }
}
void push_stack_a(t_stack **stack_a, t_stack **stack_b)
{
    int max_i;
	while (*stack_b)
	{
	    max_i = find_max_index(*stack_b);
        move_max_to_top(stack_b, max_i);
        pa(stack_a, stack_b);
		
	}

}