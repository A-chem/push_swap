#include "../include/push_swap.h"

void validate_input(int ac, char **av, t_data *data)
{
    int i;
    char *temp;
 
    i = 1;
    while (i < ac)
    {
      if(av[i][0] == '\0')
      {
        printf("Error: Empty input.\n");
        exit(1);
      }
        temp = data->str;
        data->str = ft_strjoin(data->str, av[i]);
        free(temp);
        temp = data->str;
        data->str = ft_strjoin(data->str, " ");
        free(temp);
      
        i++;
    }
    if (input_valid(data) == 0)
    {
        printf("Invalid input: check for duplicates or non-integer values.\n");
        exit(1);
    }
}
void sort_stack(t_stack **stack_a, t_stack **stack_b)
{
  int size ;
  size = size_stack(*stack_a);
    if (size == 1)
    return ;
    else if (size == 2)
        sort_two(stack_a);
    else if (size == 3)
        sort_three(stack_a);
    else if (size == 4)
      sort_four(stack_a, stack_b);
    else if (size == 5)
      sort_five(stack_a, stack_b);
    else if (size > 5 && size <= 100)
        sort_chunk(stack_a, stack_b, 16);
     else if (size > 100)
        sort_chunk(stack_a, stack_b, 33);
}
void f()
{
    system("leaks push_swap");
}
int main(int ac, char **av)
{
     //atexit(f);
   t_stack *stack_a = NULL;
   t_stack *stack_b = NULL;
  int size;
    t_data data;

    if (ac < 2)
      return (0);
 validate_input(ac, av, &data);
 stack_a = init_stack(&stack_a, &data);
 sort_stack(&stack_a, &stack_b);
 free_data(&data);
 free_stack(&stack_a);
 free_stack(&stack_b);
}

// ./push_swap 922337203685477580100
// ./push_swap " 0"0
// ./push_swap "  "
// ./push_swap " "1" "
// ./push_swap "  -"0"2 -"1"0 "
// ./push_swap "  -"0"2 -"1"0 "