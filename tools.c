#include "philo.h"

int	ft_atoi_v2(char *str)

{
	size_t	i;
	int		sign;
	long	nbr;

	nbr = 0;
	sign = 1;
	i = 0;
	while (*str == ' ')
		str++;
	if (str[i] == '-' && str[i + 1] != ' ')
	{
		i++;
		sign = sign * -1;
	}
	else if (str[i] == '+' && str[i + 1] != ' ')
		i++;
	nbr = calculate_number(str + i, sign);
	return (nbr);
}

long	calculate_number(char *str, int sign)
{
	size_t	i;
	long	nbr;
	int		digit;

	nbr = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			digit = str[i] - '0';
			nbr = nbr * 10 + digit;
			if ((sign * nbr) > INT_MAX || (sign * nbr) < INT_MIN){
            printf("error int max\n");
                exit(1);
            }
		}
		else{
        printf("wrong input\n");
            exit(1);
        }
		i++;
	}
	return (nbr * sign);
}