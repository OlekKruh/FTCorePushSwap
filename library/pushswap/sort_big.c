/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 12:13:20 by okruhlia          #+#    #+#             */
/*   Updated: 2025/12/07 12:13:25 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	size_t	len_a;
	t_stack	*smallest;

	len_a = stack_length(*stack_a);
	if (len_a == 5)
		sort_five(stack_a, stack_b);
	else
	{
		while (len_a-- > 3)
			pb(stack_b, stack_a);
	}
	sort_small(stack_a);
	while (*stack_b)
	{
		init_stack(*stack_a, *stack_b);
		move_nodes(stack_a, stack_b);
	}
	set_current_position(*stack_a);
	smallest = find_smallest_node(*stack_a);
	if (smallest->above_median)
		while (*stack_a != smallest)
			ra(stack_a);
	else
		while (*stack_a != smallest)
			rra(stack_a);
}
