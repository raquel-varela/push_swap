/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:14:15 by rvarela           #+#    #+#             */
/*   Updated: 2024/03/22 14:00:53 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//set cost to push the node from b to a
void	set_cost(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (a->above_median == 0)
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median == 1)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

//Find the cheapest node to move from b to a in the current stack config
void	set_cheapest(t_stack_node *b)
{
	long			smallest_cost;
	t_stack_node	*best_match_node;

	if (b == NULL)
		return ;
	smallest_cost = INT_MAX;
	while (b)
	{
		if (b->push_cost < smallest_cost)
		{
			smallest_cost = b->push_cost;
			best_match_node = b;
		}
		b = b->next;
	}
	(best_match_node->cheapest) = 1;
}
