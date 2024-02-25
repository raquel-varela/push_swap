/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:22:13 by rvarela           #+#    #+#             */
/*   Updated: 2024/02/25 16:47:33 by rvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap_op(t_stack_node **stack)
{
	t_stack_node	*tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = (*stack);
	(*stack) = tmp;
}

void	sa(t_stack_node **a)
{
	swap_op(a);
	write (1, "sa\n", 3);
}

void	sb(t_stack_node **b)
{
	swap_op(b);
	write (1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap_op(a);
	swap_op(b);
	write (1, "ss\n", 3);
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
	sa(&a);
	printf("%i, %i, %i\n", a->nbr, a->next->nbr, a->next->next->nbr);
}*/
