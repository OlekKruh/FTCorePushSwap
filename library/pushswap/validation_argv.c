/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:06:58 by okruhlia          #+#    #+#             */
/*   Updated: 2025/12/06 12:40:41 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	argv_validation(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	if (argc == 2)
		return (validate_single_argv(argv[1]));
	else
		return (validate_multiple_argv(argc - 1, argv + 1));
}

// strings(arguments) validation
int	validate_multiple_argv(size_t args_quant, char **argv)
{
	size_t	arg_id;

	arg_id = 0;
	if (args_quant <= 2)
		return (1);
	while (arg_id < args_quant)
	{
		if (validate_fig_str(argv[arg_id]))
			return (1);
		arg_id++;
	}
	return (0);
}

//string validation if single arg
int	validate_single_argv(char *arg)
{
	char	**new_argv;
	size_t	new_argc;
	int		result;

	if (!arg)
		return (1);
	new_argc = sub_str_count(arg, ' ');
	new_argv = ft_split(arg, ' ');
	result = validate_multiple_argv(new_argc, new_argv);
	free_new_argv(new_argv);
	return (result);
}

// validating single fig appeared as string
int	validate_fig_str(char *str)
{
	size_t		str_id;
	long long	result;
	int			sign;

	str_id = 0;
	result = 0;
	sign = 1;
	if ((str[str_id] == '+' || str[str_id] == '-') && str[str_id + 1] != '\0')
	{
		if (str[str_id] == '-')
			sign = -1;
		str_id++;
	}
	while (ft_isdigit(str[str_id]) && str[str_id] != '\0')
	{
		result = result * 10 + str[str_id] - '0';
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && (-result) < INT_MIN))
			return (1);
		str_id++;
	}
	if (str[str_id] != '\0')
		return (1);
	return (0);
}

void	free_new_argv(char **argv)
{
	size_t	id;

	id = 0;
	if (!argv)
		return ;
	while (argv[id])
		free(argv[id++]);
	free(argv);
}
