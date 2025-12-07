/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:56:48 by okruhlia          #+#    #+#             */
/*   Updated: 2025/12/06 12:36:30 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argv_validation(argc, argv))
		invalid_argv();
	stack_a_creating(&stack_a, argc, argv);
	if (sorted_validation(stack_a))
	{
		if (stack_length(stack_a) == 2)
			sa(&stack_a);
		else if (stack_length(stack_a) == 3)
			sort_small(&stack_a);
		else
			sort_big(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	return (0);
}
