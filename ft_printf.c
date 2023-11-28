/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:46:27 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/28 18:01:52 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "aux_printf.h"

int	ft_printf(const char *s, ...)
{
	char	*c;
	int		normal;
	int		res;
	va_list	argv;

	va_start(argv, s);
	c = (char *)s;
	normal = 0;
	res = 0;
	while (*c)
	{
		if (*c == '%')
		{
			write(1, (c - normal), normal);
			res += normal;
			normal = 0;
			res += parse_conversion(&c, &argv, 1);
			continue ;
		}
		normal ++;
		c ++;
	}
	va_end(argv);
	write(1, c - normal, normal);
	return (res + normal);
}
