/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comand_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:05:12 by okruhlia          #+#    #+#             */
/*   Updated: 2025/12/04 20:40:21 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (head == NULL || *head == NULL || (*head)->next_node == NULL)
		return ;
	first = *head;
	second = (*head)->next_node;
	last = find_last_node(*head);
	last->next_node = first;
	first->prev_node = last;
	first->next_node = NULL;
	second->prev_node = NULL;
	*head = second;
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
