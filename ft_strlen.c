/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/14 17:17:52 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_strlen(char *c)
{
	unsigned long long	res;

	if (c == 0)
		return (0);
	res = 0;
	while (c[res])
		res ++;
	return (res);
}
