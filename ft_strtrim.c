/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/23 15:50:16 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_is_in(const char c, const char *s)
{
	size_t	cur;

	cur = 0;
	while (s[cur])
		if (c == s[cur ++])
			return (1);
	return (0);
}

static char	*ft_empty_string(void)
{
	char	*res;

	res = malloc(1);
	if (!res)
		return (0);
	res[0] = 0;
	return (res);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*res;
	size_t	first;
	size_t	cur;
	size_t	last;

	cur = 0;
	while (ft_is_in(s1[cur], set))
		cur ++;
	if (s1[cur] == 0)
		return (ft_empty_string());
	first = cur;
	last = cur;
	while (s1[cur])
	{
		if (!ft_is_in(s1[cur], set))
			last = cur;
		cur ++;
	}
	res = malloc((last - first + 2) * sizeof(char));
	if (!res)
		return (0);
	ft_strlcpy(res, &s1[first], last - first + 2);
	res[last - first + 1] = 0;
	return (res);
}
