/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:33:16 by rvarela           #+#    #+#             */
/*   Updated: 2024/03/22 14:52:52 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rev_rot_op(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*sec_last;
	t_stack_node	*second_last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	last = find_last_node(*stack);
	sec_last = (*stack);
	while (sec_last && sec_last->next && sec_last->next->next)
	{
		sec_last = sec_last->next;
	}
	second_last = sec_last;
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack_node **a)
{
	rev_rot_op(a);
	write (1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	rev_rot_op(b);
	write (1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rev_rot_op(a);
	rev_rot_op(b);
	write (1, "rrr\n", 4);
}

void	rrr_both(t_stack_node **a, t_stack_node **b,
	t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b);
	is_above_median(*a);
	is_above_median(*b);
}

/*int	main()
{
	t_stack_node	*a;

	a = malloc(sizeof(t_stack_node));
	a->next = malloc(sizeof(t_stack_node));
	a->next->next = malloc(sizeof(t_stack_node));
	a->nbr = 42;
	a->next->nbr = 1337;
	a->next->next->nbr = -21;
	a->prev = NULL;
	a->next->prev = a;
	a->next->next->prev = a->next;
	a->next->next->next = NULL;
	printf("%i, %i, %i\n", a->nbr, a->next->nbr, a->next->next->nbr);
	rev_rot_op(&a);
	printf("%i, %i, %i\n", a->nbr, a->next->nbr, a->next->next->nbr);
}*/