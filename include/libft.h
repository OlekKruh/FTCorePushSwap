/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:19:47 by okruhlia          #+#    #+#             */
/*   Updated: 2025/12/11 22:20:11 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <unistd.h>

int		ft_isdigit(int dig);
char	**ft_split(const char *src, char spl);
int		ft_toupper(int arg);
char	*ft_strchr(const char *str, int ch);
int		ft_strlen(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
void	*ft_memcpy(void *dest, const void *src, size_t len);
size_t	sub_str_count(const char *str, char spl);
int		ft_atoi(const char *src);

#endif
