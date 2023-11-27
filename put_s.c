/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:46:27 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/27 18:46:11 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_printf.h"

static int	padit(t_params params, int l, int fd)
{
	int	c;

	c = 0;
	if (params.left_space_pad)
	{
		while (c < l)
		{
			write(fd, " ", 1);
			c ++;
		}
	}
	else
	{
		while (c < l)
		{
			write(fd, "0", 1);
			c ++;
		}
	}
	return (l);
}

int	put_s(char **c, va_list *argv, int fd, t_params params)
{
	int		l;
	int		printed;
	char	*s;

	(*c)++;
	s = va_arg(*argv, char *);
	l = (int)ft_strlen(s);
	printed = l;
	if (params.precision >= 0 && params.precision < l)
		printed = params.precision;
	if (params.min_width > printed && \
			(params.left_zero_pad || params.left_space_pad))
		printed += padit(params, params.min_width - printed, fd);
	write(fd, s, printed);
	if (params.min_width > printed && \
			!params.left_zero_pad && !params.left_space_pad)
		printed += padit(params, params.min_width - printed, fd);
	return (printed);
}
