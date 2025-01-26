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
int get_rotation_cost(size_t index, size_t stack_size)
{
    int rotation_cost;
    int stack_size_half;
    stack_size_half = stack_size / 2;
    rotation_cost = index;
    if (index > stack_size_half)
        rotation_cost = stack_size - index ;
    return (rotation_cost);
}
int find_position_in_a(t_stack *stack_a , int value)
 {
    int position_in_a;
    int data = INT_MAX;
    position_in_a = 0;
        while(stack_a)
        {
            if (stack_a ->data > value && stack_a->data < data)
            {
                position_in_a = stack_a->index;
                data = stack_a->data;
            }
            stack_a = stack_a->next;
        }
        return (position_in_a);
 }
t_stack *find_cheapest(t_stack *stack_a , t_stack *stack_b , size_t stack_size_a , size_t stack_size_b)
 {
    t_stack *cheapest = NULL;
    int min_cost = INT_MAX;
    int cost_total = 0;
    int cost_a;
    int cost_b;
    int position_in_a;

    
    while (stack_b)
    {
        position_in_a = find_position_in_a(stack_a, stack_b->data);
        cost_a = get_rotation_cost(position_in_a, stack_size_a);
        cost_b = get_rotation_cost(stack_b->index, stack_size_b);
        cost_total = cost_a + cost_b;
        if (cost_total < min_cost)
        {
        min_cost = cost_total;
        cheapest = stack_b;
        }
        printf("position_a : %d\n", position_in_a);
        printf("stack_b : %d\n", stack_b->data);
        printf("cost a : %d\n", cost_a);
        printf("cost b : %d\n", cost_b);
        printf("cost total : %d\n", cost_total);
        stack_b = stack_b->next;
    }
    return (cheapest);
 }
 void push_cheapest_to_a(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest, size_t position_in_a)
{
    int max = max_stack(*stack_a);
    int min = min_stack(*stack_a);
    printf ("max : %d\n", max);
    printf ("min : %d\n", min);
     while (cheapest->data != (*stack_b)->data)
    {
        if (cheapest->index < size_stack (*stack_b) / 2)
            rb(stack_b);
        else if (cheapest->index > size_stack (*stack_b) / 2)
            rrb(stack_b);
    }
    
  if (cheapest->data > max)
  {
    while (*stack_a)
    {
        if ((*stack_a)->data == max)
        {
        position_in_a = (*stack_a)->index;
        break;
        }
        (*stack_a) = (*stack_a)->next;
    }
    if (position_in_a > size_stack(*stack_a) / 2)
    position_in_a = size_stack(*stack_a) - position_in_a;
  }
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
         position_in_a = size_stack(*stack_a) - position_in_a;
            while (position_in_a != 0)
            {
                rra(stack_a);
                position_in_a--;
            }
              pa(stack_a, stack_b);
        }
        index_stack (stack_a, stack_b);

}
 void    sort_stack(t_stack **stack_a, t_stack **stack_b)
{
   t_stack *cheapest  = NULL;
  
   int position_in_a;
   int size = size_stack(*stack_a);
     while (size > 3)
    {
        pb (stack_a, stack_b);
        size--;
    }
    sort_three(stack_a);
    index_stack(stack_a, stack_b);
    print_stack(*stack_a, "stack_a");
    print_stack(*stack_b, "stack_b");
   while (stack_b)
   {
    cheapest = find_cheapest( *stack_a, *stack_b, size_stack(*stack_a), size_stack(*stack_b));
    index_stack(stack_a, stack_b);
    position_in_a = find_position_in_a(*stack_a, cheapest->data), size_stack(*stack_a);
    push_cheapest_to_a( stack_a, stack_b, cheapest , position_in_a);
    printf("cheapest : %d\n", cheapest->data);
    printf("position in a : %d\n", position_in_a);
    print_stack(*stack_a, "stack_a");
    print_stack(*stack_b, "stack_b");
    (*stack_b) = (*stack_b)->next;
    }
}

