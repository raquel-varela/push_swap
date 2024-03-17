/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:39:45 by rvarela           #+#    #+#             */
/*   Updated: 2024/03/17 17:53:51 by rvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*if the 1st is biggest ra, else if the 2nd is biggest rra, if 1st > 2nd sa*/
void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;	

	biggest_node = find_max_node(*a);
	if (biggest_node == *a)
		ra(a);
	else if (biggest_node == (*a)->next)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}
