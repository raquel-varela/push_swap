/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:42:14 by rvarela           #+#    #+#             */
/*   Updated: 2024/03/17 12:54:05 by rvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static long	ft_atol(const char *str)
{
	long	num;
	int		isneg;
	int		i;

	num = 0;
	isneg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * isneg);
}

/*If i have to free av from the HEAP i can use a flag in the function below*/
void	stack_init(t_stack_node **stack, char **av, int ac2)
{
	long	nbr;
	int		i;

	i = 1;
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
	if (ac2 == 2)
		free_av_split(av);
}
