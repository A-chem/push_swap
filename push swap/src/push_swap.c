#include "../include/push_swap.h"

int validate_input(int ac, char **av, t_data *data)
{
    int i;
    char *temp;
 
    i = 1;
    while (i < ac)
    {
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
        return (0);
    }
    return (1);
}
void f()
{
    system("leaks push_swap");
}
int main(int ac, char **av)
{
     atexit(f);
   t_stack *stack_a = NULL;
   t_stack *stack_b = NULL;
    t_data data;
    if (ac < 2)
      return (0);
  validate_input(ac, av, &data);
  stack_a = init_stack(&stack_a, &data);
  sort_stack(&stack_a, &stack_b);
//   int i = 0;
//   while (stack_a)
//   {
//     printf("stack_a[%d] = %d\n", i, stack_a->data);
//     stack_a = stack_a->next;
//     i++;
//   }
//   i = 0;
//   while (stack_b)
//   {
//     printf("stack_b[%d] = %d\n", i, stack_b->data);
//     stack_b = stack_b->next;
//     i++;
//    }
   free_data(&data);
   free_stack(&stack_a);
   free_stack(&stack_b);
}
