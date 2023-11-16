/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/16 16:21:27 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	res;
	unsigned char	cc;
	char	*ss;

	if (c < 0 || c > 255 || n == 0)
		return (0);
	cc = c;
	res = 0;
	ss = (char *)s;
	while (res < n - 1 && ((unsigned char)ss[res]) != cc)
		res ++;
	if (((unsigned char)ss[res]) == cc)
		return ((void *)&ss[res]);
	return (0);
}
