/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/17 14:02:38 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	cb;
	size_t	cl;
	char	*where;
	char	*what;

	if (!little[0])
		return ((char *)big);
	if (len == 0)
		return (0);
	cb = 0;
	where = (char *)big;
	what = (char *)little;
	while (cb < len && where[cb])
	{
		cl = 0;
		while (what[cl] && where[cb + cl] == what[cl])
		{
			if (cb + cl >= len)
				return (0);
			cl ++;
		}
		if (!what[cl])
			return (&where[cb]);
		cb ++;
	}
	return (0);
}
