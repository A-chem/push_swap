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
   if (a < b && b > c && c > a) // 1 3 2
    {
        rra(stack_a);
        sa(stack_a);
    }
    else if (a < b && b > c && c < a) // 2 3 1
        rra(stack_a);
    else if(a > b && b < c && c > a) // 2 1 3
        sa(stack_a);
    else if(a > b && b < c && c < a)// 3 1 2
    {
       rra (stack_a);
       rra (stack_a);
    }
    else if(a > b && b > c && c < a)// 3 2 1 
    {
        sa(stack_a);
        rra(stack_a);
    }
}
int min_stack (t_stack *stack)
{
    int min;
    min = stack->data;
    while (stack)
    {
        if (stack->data < min)
            min = stack->data;
        stack = stack->next;
    }
    return (min);
}
int max_stack (t_stack *stack)
{
    int max;
    max = stack->data;
    while (stack)
    {
        if (stack->data > max)
            max = stack->data;
        stack = stack->next;
    }
    return (max);
}
size_t size_stack(t_stack *stack)
{
    size_t size;

    size = 0;
    while (stack)
    {
        size++;
        stack= stack->next;
    }
    return (size);
}
 void index_stack(t_stack **stack_a, t_stack **stack_b)
 {
    size_t i;
    t_stack *temp;
    i = 0;
    temp = *stack_a;
    while (temp)
    {
        temp->index = i;
        temp = temp->next;
        i++;
    }
    temp = *stack_b;
    i = 0;
    while (temp)
    {
        temp->index = i;
        temp = temp->next;
        i++;
    }
 }
int get_rotation_cost(t_stack *stack, size_t index, size_t stack_size)
{
    int rotation_cost;
    int stack_size_half;
    stack_size_half = stack_size / 2;
    rotation_cost = index;
    if (index > stack_size_half)
        rotation_cost = stack_size - index;
    return (rotation_cost);
}
int find_position_in_b(t_stack *stack_a , int value)
 {
    int position;
    int stack_size;
    stack_size = size_stack(stack_a);
    position = 0;
    return (position);  
 }
t_stack *find_cheapest(t_stack *stack_a , t_stack *stack_b , size_t stack_size_a , size_t stack_size_b)
 {
    t_stack *cheapest = NULL;
    int min_cost = INT_MAX;
    int cost_total = 0;
    int cost_a;
    int cost_b;

    
    while (stack_b)
    {
        cost_a = get_rotation_cost(stack_a, find_position_in_b(stack_a, stack_a->data), stack_size_a);
        cost_b = get_rotation_cost(stack_b, stack_b->index, stack_size_b);
        cost_total = cost_a + cost_b;
        printf("stack_a->data : %d\n", stack_b->data);
        printf("cost_a : %d\n", cost_a);
        printf("cost_b : %d\n", cost_b);
        printf("cost_total : %d\n", cost_total);
        if (cost_total < min_cost)
        {
        min_cost = cost_total;
        cheapest = stack_b;
        }
        stack_b = stack_b->next;
    }
    return (cheapest);
 }
 void push_cheapest_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest, size_t position_in_a)
{
     while (cheapest->data != (*stack_b)->data)
    {
        if (cheapest->data > size_stack (*stack_b) / 2)
            rb(stack_b);
        else if (cheapest->data < size_stack (*stack_b) / 2)
            rrb(stack_b);
    }
    if(cheapest->data == (*stack_a)->max)
    {
        pa(stack_a, stack_b);
        ra(stack_a);
    }
    else if (cheapest->data == (*stack_a)->min)
        pa(stack_a, stack_b);
        if (position_in_a < size_stack(*stack_a) / 2)
        {
            while (position_in_a != 0)
            {
                ra(stack_a);
                position_in_a--;
            }
            pa(stack_a, stack_b);
        }
        else
        {
            while (position_in_a != 0)
            {
                rra(stack_a);
                position_in_a--;
            }
            pa(stack_a, stack_b);
        }
}
 void    sort_stack(t_stack **stack_a, t_stack **stack_b)
{
   t_stack *cheapest  = NULL;
  
   int position_in_a;
   int i = 1;
     while (size_stack(*stack_a) > 3)
    {
        pb (stack_a, stack_b);
        index_stack(stack_a, stack_b);
    }
    sort_three(stack_a);
     print_stack(*stack_a, "stack_a");
     print_stack(*stack_b,  "stack_b");
   while (i)
   {
    index_stack(stack_a, stack_b);
    cheapest = find_cheapest( *stack_a, *stack_b, size_stack(*stack_a), size_stack(*stack_b));
    printf("cheapest->data : %d\n", cheapest->data);
    position_in_a = find_position_in_b(*stack_a, cheapest->data);
    printf("position_in_b : %d\n", position_in_a);
    push_cheapest_to_b( stack_a, stack_b, cheapest , position_in_a);
    print_stack(*stack_a, "stack_a");
    print_stack(*stack_b, "stack_b");
    i--;
    }

}

