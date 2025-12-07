/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_lib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 14:37:50 by okruhlia          #+#    #+#             */
/*   Updated: 2025/10/23 21:42:36 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include "libft.h"

int				ft_printf(const char *src, ...);
size_t			print_char(int c);
size_t			print_str(char *str);
size_t			print_fig(long long fig, unsigned int division, char spec);
char			*ft_uinttostr(unsigned long long fig, unsigned int division);
unsigned int	ft_unilen(unsigned long long fig, unsigned int division);
void			str_to_upper(char *str);

#endif
