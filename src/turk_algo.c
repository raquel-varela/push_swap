/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:52:03 by rvarela           #+#    #+#             */
/*   Updated: 2024/02/23 18:42:58 by rvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*move nodes b to a
 *1 - emerge the target nodes
 *2 - push in a */
static void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest_node(*b);
	if (cheapest_node->above_median == 1
		&& cheapest_node->target_node->above_median == 1)
	{		
		while (*a != cheapest_node->target_node && *b != cheapest_node)
			rr(a, b);
	}
	else if (cheapest_node->above_median == 0
		&& cheapest_node->target_node->above_median == 0)
	{		
		while (*a != cheapest_node->target_node && *b != cheapest_node)
			rrr(a, b);
	}
	is_above_median(*a);
	is_above_median(*b);
	while (*b != cheapest_node)
	{
		if (cheapest_node->above_median == 1)
			rb(b);
		else
			rrb(b);
	}
	while (*a != (*b)->target_node)
	{
		if ((*b)->target_node->above_median == 1)
			ra(a);
		else
			rra(a);
	}
	push_op(a, b, 'a');
}


/*push all node in b except 3
 *sort 3
 *find the cheapest node for every config
 *push everything back in order to a*/
void	turk_algo(t_stack_node **a, t_stack_node **b)
{
	int				len_a;
	t_stack_node	*smallest;

	len_a = stack_len(*a);
	while (len_a-- > 3)
		push_op(b, a, 'b');
	sort_three(a);
	while (*b)
	{
		prepare_nodes(*a, *b);
		move_nodes(a, b);
	}
	is_above_median(*a);
	smallest = find_min_node(*a);
	if (smallest->above_median == 1)
	{
		while (*a != smallest)
			ra(a);
	}
	else
	{
		while (*a != smallest)
			rra(a);
	}
}
