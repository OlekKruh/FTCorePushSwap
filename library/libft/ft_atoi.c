/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okruhlia <okruhlia@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:19:47 by okruhlia          #+#    #+#             */
/*   Updated: 2025/09/26 13:53:05 by okruhlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *src)
{
	int		id;
	int		sign;
	int		res;

	id = 0;
	sign = 1;
	res = 0;
	while (src[id] == 32 || (9 <= src[id] && src[id] <= 13))
		id++;
	if (src[id] == '+')
		id++;
	else if (src[id] == '-')
	{
		sign *= -1;
		id++;
	}
	while ('0' <= src[id] && src[id] <= '9')
		res = res * 10 + src[id++] - '0';
	return (sign * res);
}
