/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_crud3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 21:49:26 by okruhlia          #+#    #+#             */
/*   Updated: 2025/12/08 00:13:02 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	init_stack(t_stack *stack_a, t_stack *stack_b)
{
	set_current_position(stack_a);
	set_current_position(stack_b);
	set_target_node(stack_a, stack_b);
	set_price(stack_a, stack_b);
	set_cheapest(stack_b);
}

void	set_current_position(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (stack == NULL)
		return ;
	median = (int)stack_length(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next_node;
		++i;
	}
}

static void	set_target_node(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match_index;

	while (stack_b)
	{
		best_match_index = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->fig > stack_b->fig
				&& current_a->fig < best_match_index)
			{
				best_match_index = current_a->fig;
				target_node = current_a;
			}
			current_a = current_a->next_node;
		}
		if (LONG_MAX == best_match_index)
			stack_b->target_node = find_smallest_node(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next_node;
	}
}

void	set_price(t_stack *stack_a, t_stack *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = (int)stack_length(stack_a);
	len_b = (int)stack_length(stack_b);
	while (stack_b)
	{
		stack_b->push_cost = stack_b->index;
		if (!(stack_b->above_median))
			stack_b->push_cost = len_b - (stack_b->index);
		if (stack_b->target_node->above_median)
			stack_b->push_cost += stack_b->target_node->index;
		else
			stack_b->push_cost += len_a - (stack_b->target_node->index);
		stack_b = stack_b->next_node;
	}
}

void	set_cheapest(t_stack *stack_b)
{
	long	best_match_value;
	t_stack	*best_match_node;

	if (NULL == stack_b)
		return ;
	best_match_value = LONG_MAX;
	while (stack_b)
	{
		if (stack_b->push_cost < best_match_value)
		{
			best_match_value = stack_b->push_cost;
			best_match_node = stack_b;
		}
		stack_b = stack_b->next_node;
	}
	best_match_node->cheapest = true;
}
