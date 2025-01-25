#include "../include/push_swap.h"
void free_double_(char **str)
{
    int i;
    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}
void free_data(t_data *data)
{
    if (data->str)
        free(data->str);
    if (data->num)
        free_double_(data->num);
}
void free_stack(t_stack **stack)
{
    t_stack *temp;
    while (*stack)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
        temp = NULL;
        }
        stack = NULL;
}
void print_stack(t_stack *stack, char *name)
{
    printf("%s: ", name);
    while (stack)
    {
        printf("%d ", stack->data);
        // printf("index %zu ", stack->index);
        stack = stack->next;
    }
    printf("\n");
}
