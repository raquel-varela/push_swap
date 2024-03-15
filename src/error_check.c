/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:09:53 by rvarela           #+#    #+#             */
/*   Updated: 2024/03/09 17:40:49 by rvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*Check syntactical mistakes (is digit or + or -)*/
int	check_syntax(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9')))
		return (0);
	if ((str[i] == '+' || str[i] == '-') && !(str[i + 1] >= '0'
			&& str[i + 1] <= '9'))
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

/*Loop into the stack to check if there are duplicates*/
int	check_duplicates(t_stack_node *node, int nbr)
{
	if (node == NULL)
		return (0);
	while (node)
	{
		if (node->nbr == nbr)
			return (1);
		node = node->next;
	}
	return (0);
}

/*free av created from split*/
void	free_av_split(char **av)
{
	int	i;

	i = 0;
	if (av == NULL || *av == NULL)
		return ;
	while (av[i])
		free(av[i++]);
	free(av);
}

/*free a stack*/
void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

/*free stack if there are errors*/
void	free_errors(t_stack_node **stack, char **av, int ac2)
{
	free_stack(stack);
	if (ac2 == 2)
		free_av_split(av);
	write (2, "Error\n", 6);
	exit(1);
}
