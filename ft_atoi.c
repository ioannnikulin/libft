/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/23 15:41:13 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == 32 || (c > 8 && c < 14));
}

int	ft_atoi(const char *nptr)
{
	long	res;
	char	sign;
	size_t	cur;

	res = 0;
	cur = 0;
	sign = 1;
	while (ft_isspace(nptr[cur]))
		cur ++;
	if (nptr[cur] == '-' || nptr[cur] == '+')
		if (nptr[cur ++] == '-')
			sign = -1;
	while (nptr[cur] && ft_isdigit(nptr[cur]))
	{
		res = res * 10 + nptr[cur] - '0';
		cur ++;
	}
	return ((int)(sign * res));
}
