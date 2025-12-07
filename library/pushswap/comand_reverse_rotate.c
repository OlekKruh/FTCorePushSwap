/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comand_reverse_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:42:29 by okruhlia          #+#    #+#             */
/*   Updated: 2025/12/04 21:35:47 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	reverse_rotate(t_stack **head)
{
	t_stack	*first;
	t_stack	*penult;
	t_stack	*last;

	if (head == NULL || *head == NULL || (*head)->next_node == NULL)
		return ;
	first = *head;
	last = find_last_node(*head);
	penult = last->prev_node;
	last->next_node = first;
	last->prev_node = NULL;
	penult->next_node = NULL;
	first->prev_node = last;
	*head = last;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
