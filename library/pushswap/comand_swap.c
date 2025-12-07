/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comand_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:54:26 by okruhlia          #+#    #+#             */
/*   Updated: 2025/12/06 12:38:25 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (head == NULL || !(*head) || !(*head)->next_node)
		return ;
	first = *head;
	second = first->next_node;
	third = second->next_node;
	first->next_node = third;
	if (third)
		third->prev_node = first;
	second->prev_node = NULL;
	second->next_node = first;
	first->prev_node = second;
	*head = second;
}

void	sa(t_stack **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
