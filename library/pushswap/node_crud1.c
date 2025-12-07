/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_crud.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 23:34:58 by okruhlia          #+#    #+#             */
/*   Updated: 2025/12/07 21:47:23 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	append_node(t_stack **stack_a, int fig)
{
	t_stack	*node;
	t_stack	*last_node;

	if (stack_a == NULL)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next_node = NULL;
	node->fig = fig;
	if (*stack_a == NULL)
	{
		*stack_a = node;
		node->prev_node = NULL;
	}
	else
	{
		last_node = find_last_node(*stack_a);
		last_node->next_node = node;
		node->prev_node = last_node;
	}
}

t_stack	*find_last_node(t_stack *node)
{
	if (node == NULL)
		return (NULL);
	while (node->next_node)
		node = node->next_node;
	return (node);
}

size_t	stack_length(t_stack *node)
{
	size_t	len;

	len = 0;
	if (node == NULL)
		return (len);
	while (node->next_node)
	{
		node = node->next_node;
		len++;
	}
	return (len);
}

void	free_stack(t_stack **head)
{
	t_stack	*current;
	t_stack	*next_node;

	current = *head;
	while (current)
	{
		next_node = current->next_node;
		free(current);
		current = next_node;
	}
	*head = NULL;
}
