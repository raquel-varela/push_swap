/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:52:03 by rvarela           #+#    #+#             */
/*   Updated: 2024/03/22 13:57:40 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	move_nodes_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest_node(*a);
	if ((cheapest_node->above_median) == 1
		&& ((cheapest_node->target_node->above_median) == 1))
		rr_both(a, b, cheapest_node);
	else if ((cheapest_node->above_median) == 0
		&& ((cheapest_node->target_node->above_median) == 0))
		rrr_both(a, b, cheapest_node);
	while (*a != cheapest_node)
	{
		if ((cheapest_node->above_median) == 1)
			ra(a);
		else
			rra(a);
	}
	while (*b != cheapest_node->target_node)
	{
		if ((cheapest_node->target_node->above_median) == 1)
			rb(b);
		else
			rrb(b);
	}
	push_op(b, a, 'b');
}

static void	move_nodes_b_to_a(t_stack_node **a, t_stack_node **b)
{
	while (*a != (*b)->target_node)
	{
		if (((*b)->target_node->above_median) == 1)
			ra(a);
		else
			rra(a);
	}
	push_op(a, b, 'a');
}

void	min_to_top(t_stack_node **a)
{
	t_stack_node	*smallest;

	smallest = find_min_node(*a);
	while ((*a)->nbr != smallest->nbr)
	{
		if ((smallest->above_median) == 1)
			ra(a);
		else
			rra(a);
	}
}

void	turk_algo(t_stack_node **a, t_stack_node **b)
{
	int				len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !(stack_sorted(*a)))
		push_op(b, a, 'b');
	if (len_a-- > 3 && !(stack_sorted(*a)))
		push_op(b, a, 'b');
	while (len_a-- > 3 && !(stack_sorted(*a)))
	{
		prepare_nodes_a(*a, *b);
		move_nodes_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		prepare_nodes_b(*a, *b);
		move_nodes_b_to_a(a, b);
	}
	is_above_median(*a);
	min_to_top(a);
}
