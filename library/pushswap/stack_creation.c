/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:13:01 by okruhlia          #+#    #+#             */
/*   Updated: 2025/12/06 12:40:06 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	stack_a_creating(t_stack **stack_a, int argc, char **argv)
{
	if (argc < 2)
		invalid_argv();
	if (argc == 2)
		proces_single_argv(stack_a, argv[1]);
	else
		proces_multiple_argv(stack_a, argc - 1, argv + 1);
	if (stack_length(*stack_a) <= 2)
		invalid_stack(stack_a);
}

void	proces_multiple_argv(t_stack **stack_a, size_t args_quant, char **argv)
{
	size_t	arg_id;
	int		fig;

	arg_id = 0;
	while (arg_id < args_quant)
	{
		fig = ft_atoi(argv[arg_id]);
		if (repetition_validation(*stack_a, fig))
			invalid_stack(stack_a);
		append_node(stack_a, fig);
		arg_id++;
	}
}

void	proces_single_argv(t_stack **stack_a, char *arg)
{
	char	**new_argv;
	size_t	new_argc;

	new_argc = sub_str_count(arg, ' ');
	new_argv = ft_split(arg, ' ');
	proces_multiple_argv(stack_a, new_argc, new_argv);
	free_new_argv(new_argv);
}
