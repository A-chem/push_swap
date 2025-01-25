#include "../include/push_swap.h"
int ft_duplicate(char **num, char *str)
{
    int i ;
    int count;
    i = 0;
    count = 0;
    while (num[i])
    {
        if (ft_atoi(num[i]) == ft_atoi(str))
            count++;
        i++;
    }
    if (count > 1)
        return (0);
    return (1);
}
int ft_check_element(char *str)
{
   int i;

    if (!str || !*str) 
        return (0);
    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (i > 0);
}
int input_valid(t_data *data)
{
    int i ;
    int j ;

    data->num  = ft_split(data ->str, ' ');
 
    if (!data->num)
        return (0);
    i = 0;
    j = 0;
    while (data->num[i])
    {
        if (ft_check_element(data->num[i]) == 0)
        {
                printf("aaaaaaa");
                    return (0);
        }
        else if (ft_atoi(data->num[i]) > INT_MAX || ft_atoi(data->num[i]) < INT_MIN)
                    return (0);
        else if (ft_duplicate(data->num, data->num[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}