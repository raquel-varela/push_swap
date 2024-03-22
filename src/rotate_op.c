/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:24:45 by rvarela           #+#    #+#             */
/*   Updated: 2024/03/22 14:41:54 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static void	rotate_op(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a)
{
	rotate_op(a);
	write (1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	rotate_op(b);
	write (1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate_op(a);
	rotate_op(b);
	write(1, "rr\n", 3);
}

void	rr_both(t_stack_node **a, t_stack_node **b,
	t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b);
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
	rotate_op(&a);
	printf("%i, %i, %i\n", a->nbr, a->next->nbr, a->next->next->nbr);
}*/