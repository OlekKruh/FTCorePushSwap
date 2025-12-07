/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:56:49 by okruhlia          #+#    #+#             */
/*   Updated: 2025/12/06 12:53:49 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#ifdef __linux__
# define NULL_PTR_STR "(nil)"
# define NULL_PTR_LEN 5
#else
# define NULL_PTR_STR "0x0"
# define NULL_PTR_LEN 3
#endif

size_t	print_null_pointer_representation(void)
{
	return (write(1, NULL_PTR_STR, NULL_PTR_LEN));
}

char	*ft_uinttostr(unsigned long long fig, unsigned int division)
{
	char			*res;
	size_t			len;
	unsigned int	digit;

	len = ft_unilen(fig, division) + 1;
	res = malloc(sizeof(char) * len);
	if (!res)
		return (NULL);
	res[--len] = '\0';
	if (fig == 0)
		res[0] = '0';
	while (fig)
	{
		digit = (fig % division);
		if (digit < 10)
			res[--len] = digit + '0';
		else
			res[--len] = (digit - 10) + 'a';
		fig /= division;
	}
	return (res);
}

unsigned int	ft_unilen(unsigned long long fig, unsigned int division)
{
	unsigned int	len;

	len = 0;
	if (fig == 0)
		return (1);
	while (fig)
	{
		fig /= division;
		len++;
	}
	return (len);
}

void	str_to_upper(char *str)
{
	size_t	id;

	id = 0;
	if (!str)
		return ;
	while (str[id])
	{
		str[id] = (char)ft_toupper(str[id]);
		id++;
	}
}

size_t	print_fig(long long fig, unsigned int division, char spec)
{
	size_t	count;
	char	*str;

	count = 0;
	if ((spec == 'd' || spec == 'i') && fig < 0)
	{
		write(1, "-", 1);
		fig = -fig;
		count++;
	}
	if (spec == 'p' && !fig)
		return (count + print_null_pointer_representation());
	str = ft_uinttostr(fig, division);
	if (!str)
		return (count);
	if (spec == 'X')
		str_to_upper(str);
	if (spec == 'p')
		count += write(1, "0x", 2);
	count += print_str(str);
	free(str);
	return (count);
}
