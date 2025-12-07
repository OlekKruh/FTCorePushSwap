/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:57:08 by okruhlia          #+#    #+#             */
/*   Updated: 2025/12/06 12:39:44 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_small(t_stack **stack_a)
{
	t_stack	*highest_value_node;

	highest_value_node = NULL;
	highest_value_node = find_highest_node(*stack_a);
	if (highest_value_node == *stack_a)
		ra(stack_a);
	else if ((*stack_a)->next_node == highest_value_node)
		rra(stack_a);
	if ((*stack_a)->fig > (*stack_a)->next_node->fig)
		sa(stack_a);
}
