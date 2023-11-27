/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_n_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:46:27 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/27 18:12:44 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_printf.h"
#define MX 65

static int	pad(size_t l, t_params params, int fd)
{
	size_t	p;

	if (params.precision <= (int)l)
		return (0);
	if (params.left_space_pad)
	{
		p = params.precision - l;
		while (p --)
			write(fd, " ", 1);
		return (params.precision - l);
	}
	else if (params.left_zero_pad)
	{
		p = params.precision - l;
		while (p --)
			write(fd, "0", 1);
		return (params.precision - l);
	}
	return (0);
}

static int	hex_prefix(t_params *params, int fd)
{
	if (!params->hex_prefix)
		return (0);
	if (params->capital_hex)
		write(fd, "0X", 2);
	else
		write(fd, "0x", 2);
	if (params->precision <= 2)
		params->precision = 0;
	else
		params->precision -= 2;
	return (2);
}

int	pad_n_put(char *c, size_t l, int fd, t_params params)
{
	size_t	res_len;

	res_len = 0;
	if (params.left_space_pad)
		params.left_zero_pad = 0;
	if (params.sign_mandatory)
		params.space_before_positive = 0;
	res_len += hex_prefix(&params, fd);
	if (params.sign_mandatory && c[MX - l] != '-')
	{
		write(fd, "+", 1);
		if (params.precision > 0)
			params.precision --;
		res_len ++;
	}
	res_len += pad(l, params, fd);
	write(fd, c, l);
	return (res_len + l);
}
