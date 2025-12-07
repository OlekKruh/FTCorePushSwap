/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 15:41:52 by okruhlia          #+#    #+#             */
/*   Updated: 2025/10/21 22:29:26 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_select(char spec, va_list ap);

int	ft_printf(const char *src, ...)
{
	va_list	ap;
	size_t	total_len;
	size_t	id;

	if (!src)
		return (0);
	id = 0;
	total_len = 0;
	va_start(ap, src);
	while (src[id] != '\0')
	{
		if (src[id] == '%')
		{
			total_len += print_select(src[id + 1], ap);
			id++;
		}
		else
			total_len += write(1, &src[id], 1);
		id++;
	}
	va_end(ap);
	return ((int)total_len);
}

size_t	print_select(const char spec, va_list ap)
{
	size_t	count;

	count = 0;
	if (spec == 'c')
		count += print_char(va_arg(ap, int));
	else if (spec == 's')
		count += print_str(va_arg(ap, char *));
	else if (spec == 'p')
		count += print_fig((unsigned long long)va_arg(ap, void *), 16, spec);
	else if (spec == 'x' || spec == 'X')
		count += print_fig(va_arg(ap, unsigned int), 16, spec);
	else if (spec == 'd' || spec == 'i')
		count += print_fig(va_arg(ap, int), 10, spec);
	else if (spec == 'u')
		count += print_fig(va_arg(ap, unsigned int), 10, spec);
	else if (spec == '%')
		count += write(1, "%", 1);
	else
		count += write(1, &spec, 1);
	return (count);
}
