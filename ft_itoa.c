/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/17 21:02:08 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	char	buf[21];
	size_t		c;
	int	is_neg;
	char	*res;
	long	nn;

	if (n == 0)
	{
		res = malloc(2 * sizeof(char));
		if (!res)
			return (0);
		res = "0";
		return (res);
	}
	nn = n;
	is_neg = 0;
	c = 20;
	ft_bzero(buf, 21);
	if (nn < 0)
	{
		nn = -nn;
		is_neg = 1;
	}
	while (nn > 0)
	{
		buf[-- c] = '0' + nn % 10;
		nn /= 10;
	}
	res = malloc((is_neg + 20 - c) * sizeof(char));
	if (!res)
		return (0);
	res[0] = '-';
	ft_strlcpy(&res[is_neg], &buf[c], 21 - c);
	return (res);
}
