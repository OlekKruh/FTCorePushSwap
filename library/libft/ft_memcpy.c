/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 22:09:03 by okruhlia          #+#    #+#             */
/*   Updated: 2025/10/09 21:11:51 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t	id;

	id = 0;
	while (id < len)
	{
		((unsigned char *)dest)[id] = ((unsigned char *)src)[id];
		id++;
	}
	return (dest);
}
