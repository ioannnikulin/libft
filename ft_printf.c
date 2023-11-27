/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:46:27 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/27 19:06:43 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "aux_printf.h"

static void	single_char_param(char **c, char orig, unsigned char *set)
{
	if (**c && **c == orig)
	{
		(*set) = 1;
		(*c)++;
	}
}

static void	numeric_param(char **c, int *set)
{
	int	neg;

	neg = 0;
	*set = 0;
	if (**c == '-')
	{
		neg = 1;
		(*c)++;
	}
	while (ft_isdigit(**c))
		*set = *set * 10 + (*((*c)++)) - '0';
	if (neg)
		*set = 0;
}

static t_params	parse_params(char **c)
{
	t_params	r;
	char		*cprev;

	cprev = 0;
	r.min_width = 0;
	r.precision = -1;
	while (cprev != *c)
	{
		cprev = *c;
		single_char_param(c, '-', &r.left_space_pad);
		single_char_param(c, '0', &r.left_zero_pad);
		single_char_param(c, '#', &r.hex_prefix);
		single_char_param(c, ' ', &r.space_before_positive);
		single_char_param(c, '+', &r.sign_mandatory);
		if (**c != '0')
			numeric_param(c, &r.min_width);
		if (**c == '.')
		{
			(*c)++;
			numeric_param(c, &r.precision);
		}
	}
	return (r);
}

int	parse_conversion(char **c, va_list *argv, int fd)
{
	t_params	params;

	(*c)++;
	params = parse_params(c);
	if (**c == 'c')
		return (put_c(c, argv, fd, params));
	else if (**c == 's')
		return (put_s(c, argv, fd, params));
	else if (**c == 'p')
		return (put_p(c, argv, fd, params));
	else if (**c == 'i' || **c == 'd')
		return (put_d(c, argv, fd, params));
	else if (**c == 'u')
		return (put_u(c, argv, fd, params));
	else if (**c == 'x' || **c == 'X')
		return (put_x(c, argv, fd, params));
	else if (**c == '%')
		return (put_percent(c, argv, fd, params));
	write(fd, "!!ERROR!!", 9);
	return (9);
}

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
