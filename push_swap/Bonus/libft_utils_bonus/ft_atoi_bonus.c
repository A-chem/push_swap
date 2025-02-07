#include "../include/checker_bonus.h"
long	ft_atoi_long(const char *str)
{
	long		nbr;
	long		sign;
	size_t		i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || ('\t' <= str[i] && str[i] <= '\r'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		if ((nbr * sign) > 2147483647 || (nbr * sign) < -2147483648)
			return (4815162342);
		i++;
	}
	return (nbr * sign);
}
int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}