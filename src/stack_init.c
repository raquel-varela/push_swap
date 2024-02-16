/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:42:14 by rvarela           #+#    #+#             */
/*   Updated: 2024/02/11 14:53:33 by rvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static long	ft_atol(char *str)
{
	long	nbr;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - 48;
		i++;
	}
	return (nbr * sign);
}

/*If i have to free av from the HEAP i can use a flag in the function below*/
void	stack_init(t_stack_node **stack, char **av, int ac2)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[i])
	{
		if (check_syntax(av[i]) == 0)
			free_errors(stack, av, ac2);
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_errors(stack, av, ac2);
		if (check_duplicates(*stack, (int)nbr) == 1)
			free_errors(stack, av, ac2);
		add_node(stack, (int)nbr);
		i++;
	}
	if (ac2)
		free_av_split(av);
}
