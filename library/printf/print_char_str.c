/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:15:39 by okruhlia          #+#    #+#             */
/*   Updated: 2025/10/19 21:08:21 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_char(int c)
{
	return (write(1, &c, 1));
}

size_t	print_str(char *str)
{
	size_t	id;
	size_t	count;

	if (!str)
		return (print_str("(null)"));
	id = 0;
	count = 0;
	while (str[id])
		count += print_char(str[id++]);
	return (count);
}
