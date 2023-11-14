/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/14 15:24:32 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dest, const void *src, unsigned long long n)
{
	unsigned long long	c;

	if (dest == src || dest == 0 || n == 0 || src == 0) 
		return (dest);
	if (dest > src)
		while (n --)
			(*(char *)&dest[n]) = *(char *)&src[n];
	else
	{
		c = -1;
		while ((++ c) < n)
			(*(char *)&dest[c]) = *(char *)&src[c];
	}
	return (dest);
}
