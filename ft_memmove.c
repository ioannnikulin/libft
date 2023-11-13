/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/13 21:03:22 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	c;

	if (dest == src || dest == NULL || n == 0 || src == NULL) 
		return (dest);
	if (dest > src)
		while (n --)
			dest[n] = src[n];
	else
	{
		c = -1;
		while ((++ c) < n)
			dest[c] = src[c];
	}
	return (dest);
}
