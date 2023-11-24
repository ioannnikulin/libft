/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_n_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:46:27 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/24 19:41:44 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_printf.h"
#define MX 65
#define ZR "00000000000000000000000000000000000000000000000000000000000000000"
#define SP "                                                                 " 

int	pad_n_put(char *c, size_t l, int fd, t_params params)
{
	size_t	res_len;

	if (params.left_space_pad)
		params.left_zero_pad = 0;
	if (params.sign_mandatory)
		params.space_before_positive = 0;
	if (params.hex_prefix)
	{
		if (params.capital_hex)
			write(fd, "0X", 2);
		else
			write(fd, "0x", 2);
		if (params.precision <= 2)
			params.precision = 0;
		else
			params.precision -= 2;
		res_len += 2;
	}
	if (sign_mandatory && c[MX - l] != '-')
	{
		write(fd, "+", 1);
		if (params.precision > 0)
			params.precision --;
		res_len ++;
	}
	if (params.precision > l)
	{
		if (params.left_space_pad)
		{
			write(fd, SP, params.precision - l);
			res_len += params.precision - l;
		}
		else if (params.left_zero_pad)
		{
			write(fd, ZR, params.precision - l);
			res_len += params.precision - l;
		}
	}
	write(fd, c, l);
	return (res_len + l);
}
