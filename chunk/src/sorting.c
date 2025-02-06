#include "../include/push_swap.h"

void    sort_two(t_stack **stack_a)
{
    if ((*stack_a)->data > (*stack_a)->next->data)
        sa(stack_a);
}
void    sort_three(t_stack **stack_a)
{
    int a;
    int b;
    int c;
    a = (*stack_a)->data;
    b = (*stack_a)->next->data;
    c = (*stack_a)->next->next->data;
   
    if (a > b && b < c && a < c)
        sa(stack_a);
    else if (a > b && b > c)
    {
        sa(stack_a);
        rra(stack_a);
    }
    else if (a > b && b < c && a > c)
        ra(stack_a);
    else if (a < b && b > c && a < c)
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if (a < b && b > c && a > c)
        rra(stack_a);
}
    

void sort_chunk(t_stack **stack_a, t_stack **stack_b, int chunk_size)
{
    int a_index;
    int *array;
    int size;
    int size_b;
    int i;

    size = size_stack(*stack_a);
    array = stack_array(*stack_a, size);
    if (!array)
        return;
    size_b = 0;
    while (*stack_a)
    {
         a_index = find_index_in_array(array, size, (*stack_a)->data);
        move_element(stack_a, stack_b, a_index, &size_b, chunk_size);
    }
    push_stack_a(stack_a , stack_b);
    free(array);
}

