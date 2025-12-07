/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:57:08 by okruhlia          #+#    #+#             */
/*   Updated: 2025/12/07 23:56:58 by okruhlia         ###   ########.fr       */
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

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	while (stack_length(*stack_a) > 3)
	{
		init_stack(*stack_a, *stack_b);
		finish_rotation(stack_a, find_smallest_node(*stack_a), 'a');
		pb(stack_b, stack_a);
	}
}