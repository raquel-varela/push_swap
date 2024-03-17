/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:14:15 by rvarela           #+#    #+#             */
/*   Updated: 2024/03/17 13:12:09 by rvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	is_above_median(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (stack == NULL)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		++i;
	}
}

static void	set_target_node_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match_index;

	while (a)
	{
		best_match_index = INT_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > best_match_index)
			{
				best_match_index = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == INT_MIN)
			a->target_node = find_max_node(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	set_target_node_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < best_match_index)
			{
				best_match_index = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == INT_MAX)
			b->target_node = find_min_node(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

//set cost to push the node from b to a
static void	set_cost(t_stack_node *a, t_stack_node *b)
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

void	prepare_nodes_a(t_stack_node *a, t_stack_node *b)
{
	is_above_median(a);
	is_above_median(b);
	set_target_node_a(a, b);
	set_cost(a, b);
	set_cheapest(a);
}

void	prepare_nodes_b(t_stack_node *a, t_stack_node *b)
{
	is_above_median(a);
	is_above_median(b);
	set_target_node_b(a, b);
}
