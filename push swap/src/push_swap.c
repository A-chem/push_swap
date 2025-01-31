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
void f()
{
    system("leaks push_swap");
}
int main(int ac, char **av)
{
    //  atexit(f);
   t_stack *stack_a = NULL;
   t_stack *stack_b = NULL;
    t_data data;
    if (ac < 2)
      return (0);
validate_input(ac, av, &data);
 stack_a = init_stack(&stack_a, &data);
  if (size_stack(stack_a) == 2)
    sort_two(&stack_a);
  else if (size_stack(stack_a) == 3)
    sort_three(&stack_a);
  else if ( size_stack(stack_a) > 3)
  {
   
     sort_stack(&stack_a, &stack_b);

  }
free_data(&data);
   free_stack(&stack_a);
free_stack(&stack_b);

}