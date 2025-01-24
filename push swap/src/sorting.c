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
        rra(stack_a);
    else if(a > b && b > c && c < a)// 3 2 1 
    {
        sa(stack_a);
        rra(stack_a);
    }
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
        rotation_cost = index - stack_size;
    return (rotation_cost);
}
t_stack *find_cheapest(t_stack *stack_a , t_stack *stack_b , size_t stack_size_a , size_t stack_size_b)
 {
    t_stack *cheapest = NULL;
    int min_cost = INT_MAX;
    int cost_total;
    int cost_a;
    int cost_b;
    size_t pos_b;
    while (stack_a && stack_b)
    {
        index_stack(&stack_a, &stack_b);
        // pos_b = find_position_in_b(stack_b, stack_a->data, stack_size_b);
        cost_a = get_rotation_cost(stack_a, stack_a->index, stack_size_a);
        cost_b = get_rotation_cost(stack_b, stack_b->index, stack_size_b);
        break;
        // cost_total = cost_a + cost_b;
        // if (cost_total < min_cost)
        // {
        // min_cost = cost_total;
        // cheapest = stack_a;
        // }
        // stack_a = stack_a->next;
        // stack_b = stack_b->next;
    }
    return (cheapest);

 }
  int find_position_in_b(t_stack *stack_b , int value, size_t stack_size)
 {
    size_t position;
    position = 0;
    int max = stack_b->data;
    int min = stack_b->data;
    while (stack_b)
    {
        if (stack_b->data > max)
        {
            max = stack_b->data;
            position = 0;
        }
        else if (stack_b->data < min)
        {
            min = stack_b->data;
            position = 0;
        }
        stack_b = stack_b->next;
    }
    if(value > max || value < min)
    {
        while (stack_b->data != max)
        {
            position++;
            stack_b = stack_b->next;
        }
        return (position + 1);
    }
        return (0);
    while (stack_b->next)
    {
        if (stack_b->data < value && stack_b->next->data > value)
            return (position + 1);
        position++;
        stack_b = stack_b->next;
     }
        return (0);
 }
 void    sort_stack(t_stack **stack_a, t_stack **stack_b)
{

    // int max ;
    // int min ;
   t_stack *cheapest  = NULL;
   size_t position;
    // max = find_max(*stack_a);
    // min = find_min(*stack_a);
    pb(stack_a, stack_b); 
    pb(stack_a, stack_b);
    if ((*stack_b)->data < (*stack_b)->next->data)
        sa(stack_b);
   while (size_stack(*stack_a) > 3)
   {
    index_stack(stack_a, stack_b);
    cheapest = find_cheapest( *stack_a, *stack_b, size_stack(*stack_a), size_stack(*stack_b));
    position = find_position_in_b( *stack_b, cheapest->data, size_stack(*stack_b));
    push_stack_b(stack_a, stack_b, cheapest,  position);;
   }


