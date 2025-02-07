#include "../include/checker_bonus.h"
void validate_input(int ac, char **av, t_data *data)
{
    int i;
    char *temp;
 
    i = 1;
    while (i < ac)
    {
      if(av[i][0] == '\0')
      {
        write(2, "Error\n", 6);
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
    if (!input_valid(data))
    {
        write(2, "Error\n", 6);
        exit(1);
    }
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
    t_data data;

    if (ac < 2)
    {
      write(2, "Error\n", 6);
        exit(1);
    }
    validate_input(ac, av, &data);
    stack_a = init_stack(&stack_a, &data);
    read_and_execute(&stack_a, &stack_b);
//  free_data(&data);
//  free_stack(&stack_a);
}