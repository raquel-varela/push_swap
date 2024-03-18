/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:27:29 by rvarela           #+#    #+#             */
/*   Updated: 2024/03/18 19:13:39 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_op(t_stack_node **dest, t_stack_node **src, char list)
{
	t_stack_node	*node;

	if (*src == NULL)
		return ;
	node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node->prev = NULL;
	if (*dest == NULL)
	{
		*dest = node;
		node->next = NULL;
	}
	else
	{
		node->next = *dest;
		node->next->prev = node;
		*dest = node;
	}
	write(1, "p", 1);
	write(1, &list, 1);
	write(1, "\n", 1);
}

/*int	main()
{
	t_stack_node	*a;
	t_stack_node	*b = NULL;

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
	push_op(&b, &a, 'b');
	printf("%i, %i\n", b->nbr, a->nbr);
}*/