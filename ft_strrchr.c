/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/16 14:19:29 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	cur;
	size_t	ret;

	cur = 0;
	ret = 0;
	while (s[cur])
	{
		if (s[cur] == c)
			ret = cur;
		cur ++;
	}
	if (c == 0)
		return ((char *)&s[cur]);
	if (ret != 0 || s[0] == c)
		return ((char *)&s[ret]);
	return (0);
}
