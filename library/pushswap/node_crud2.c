/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_crud2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 21:45:28 by okruhlia          #+#    #+#             */
/*   Updated: 2025/12/08 00:12:39 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*find_highest_node(t_stack *stack_a_node)
{
	int		highest_value;
	t_stack	*highest_node;

	highest_node = NULL;
	highest_value = INT_MIN;
	if (stack_a_node == NULL)
		return (NULL);
	while (stack_a_node)
	{
		if (stack_a_node->fig > highest_value)
		{
			highest_value = stack_a_node->fig;
			highest_node = stack_a_node;
		}
		stack_a_node = stack_a_node->next_node;
	}
	return (highest_node);
}

t_stack	*find_smallest_node(t_stack *stack)
{
	long	smallest;
	t_stack	*smallest_node;

	if (stack == NULL)
		return (NULL);
	smallest = INT_MAX;
	while (stack)
	{
		if (stack->fig < smallest)
		{
			smallest = stack->fig;
			smallest_node = stack;
		}
		stack = stack->next_node;
	}
	return (smallest_node);
}

t_stack	*return_cheapest(t_stack *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next_node;
	}
	return (NULL);
}
