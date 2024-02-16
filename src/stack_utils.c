/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:31:08 by rvarela           #+#    #+#             */
/*   Updated: 2024/02/16 17:11:13 by rvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*Search for the last node and add a node*/
t_stack_node	*find_last_node(t_stack_node *node)
{
	if (node == NULL)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

void	add_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->nbr = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

t_stack_node	*find_max_node(t_stack_node *node)
{
	t_stack_node	*max_node;
	long			max;

	if (node == NULL)
		return (NULL);
	max = node->nbr;
	while (node->next)
	{
		if (node->nbr > max)
		{
			max = node->nbr;
			max_node = node;
		}
		node = node->next;
	}
	return (max_node);
}

t_stack_node	*find_min_node(t_stack_node *node)
{
	t_stack_node	*min_node;
	long			min;

	if (node == NULL)
		return (NULL);
	min = node->nbr;
	while (node->next)
	{
		if (node->nbr < min)
		{
			min = node->nbr;
			min_node = node;
		}
		node = node->next;
	}
	return (min_node);
}

int	stack_len(t_stack_node *node)
{
	int	len;

	len = 0;
	if (!node)
		return (0);
	while (node)
	{
		len++;
		node = node->next;
	}
	return (len);
}
