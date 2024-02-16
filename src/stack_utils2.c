/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:31:08 by rvarela           #+#    #+#             */
/*   Updated: 2024/02/16 17:11:05 by rvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	stack_sorted(t_stack_node *node)
{
	if (!node)
		return (true);
	while (node->next)
	{
		if (node->nbr > node->next->nbr)
			return (false);
		node = node->next;
	}
	return (true);
}
