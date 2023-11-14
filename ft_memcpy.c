/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/14 15:23:12 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, unsigned long long n)
{
	if (dest == src || dest == 0 || src == 0 || n == 0)
		return (dest);
	while (n --)
	{
		(*(char *)&dest[n]) = *(char *)&src[n];
	}
	return (dest);
}
