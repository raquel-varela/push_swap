/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:57:39 by rvarela-          #+#    #+#             */
/*   Updated: 2024/03/22 14:21:10 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*read, write*/
# include <unistd.h>
/*malloc, free, exit*/
# include <stdlib.h>
/*MAX MIN*/
# include <limits.h>
/*booleans*/
# include <stdbool.h>
/*printf for tests*/
# include <stdio.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	int					cheapest;
	int					above_median;
	struct s_stack_node	*target_node;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}					t_stack_node;

//Utils
char			**ft_split(char *str, char sep);

//Handle errors
int				check_syntax(char *str);
int				check_duplicates(t_stack_node *node, int nbr);
void			free_errors(t_stack_node **stack, char **av, int ac2);
void			free_av_split(char **av);
void			free_stack(t_stack_node **stack);

//Stack initiation
void			stack_init(t_stack_node **stack, char **av, int ac2);

//Nodes initiation
void			prepare_nodes_a(t_stack_node *a, t_stack_node *b);
void			prepare_nodes_b(t_stack_node *a, t_stack_node *b);

//Stack utils
t_stack_node	*find_last_node(t_stack_node *stack);
t_stack_node	*find_max_node(t_stack_node *node);
t_stack_node	*find_min_node(t_stack_node *node);
t_stack_node	*get_cheapest_node(t_stack_node *stack);
void			add_node(t_stack_node **stack, int nbr);
void			is_above_median(t_stack_node *stack);
void			set_cheapest(t_stack_node *b);
void			set_cost(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *b);
int				stack_len(t_stack_node *node);
bool			stack_sorted(t_stack_node *node);

//Operations
void			push_op(t_stack_node **dest, t_stack_node **src, char list);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rr_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			rrr_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);

//Algorithm
void			sort_three(t_stack_node **a);
void			turk_algo(t_stack_node **a, t_stack_node **b);

#endif
