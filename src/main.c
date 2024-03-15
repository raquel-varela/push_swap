/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:56:53 by rvarela-          #+#    #+#             */
/*   Updated: 2024/03/15 15:55:03 by rvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	stack_init(&a, av, ac);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			ra(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			turk_algo(&a, &b);
	}
	free_stack(&a);
	return (0);
}
