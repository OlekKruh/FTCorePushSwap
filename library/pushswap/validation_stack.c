/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 09:56:07 by okruhlia          #+#    #+#             */
/*   Updated: 2025/12/07 16:10:09 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	repetition_validation(t_stack *node, int fig)
{
	if (node == NULL)
		return (0);
	while (node)
	{
		if (node->fig == fig)
			return (1);
		node = node->next_node;
	}
	return (0);
}

int	sorted_validation(t_stack *node)
{
	if (node == NULL)
		return (1);
	while (node->next_node)
	{
		if (node->fig > node->next_node->fig)
			return (false);
		node = node->next_node;
	}
	return (true);
}
