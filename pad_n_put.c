/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_n_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:46:27 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/28 17:16:37 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_printf.h"
#define MX 65

static void	pad(int len, char c, int fd)
{
	while (len --)
		write(fd, &c, 1);
}

static int	hex_prefix(t_params params, int fd)
{
	if (!params.hex_prefix)
		return (0);
	if (params.capital_hex)
		write(fd, "0X", 2);
	else
		write(fd, "0x", 2);
	return (2);
}

static int	sign(char orig, t_params params, int fd)
{
	if (orig == '-')
	{
		write(fd, &orig, 1);
		return (1);
	}
	if (params.sign_mandatory)
	{
		write(fd, "+", 1);
		return (1);
	}
	if (params.space_before_positive)
	{
		write(fd, " ", 1);
		return (1);
	}
	return (0);
}

static void	calc_lens(int lens[4], t_params params, char *c, int l)
{
	lens[3] = 0;
	lens[2] = l;
	lens[1] = 0;
	lens[0] = 0;
	if (params.precision > l)
		lens[1] = params.precision - l;
	if (params.left_space_pad && params.min_width > lens[1] + lens[2])
		lens[3] = params.min_width - lens[1] - lens[2];
	else if (params.left_zero_pad && params.min_width > lens[1] + lens[2])
		lens[1] = params.min_width - lens[2];
	else if (!params.left_space_pad && !params.left_zero_pad \
			&& params.min_width > lens[2])
		lens[0] = params.min_width - lens[2];
	if ((params.sign_mandatory || params.space_before_positive \
			|| c[MX - l] != '-') && lens[0] > 0)
		lens[0]--;
	if (params.hex_prefix)
	{
		if (lens[0] > 1)
			lens[0] -= 2;
		else
			lens[0] = 0;
	}
}

int	pad_n_put(char *c, int l, int fd, t_params params)
{
	int	lens[4];

	if (params.left_space_pad)
		params.left_zero_pad = 0;
	if (params.sign_mandatory)
		params.space_before_positive = 0;
	calc_lens(lens, params, c, l);
	pad(lens[0], ' ', fd);
	lens[0] += sign(c[MX - l], params, fd);
	lens[0] += hex_prefix(params, fd);
	pad(lens[1], '0', fd);
	if (c[MX - l] == '-')
		write(fd, &c[MX - l + 1], l - 1);
	else
		write(fd, &c[MX - l], l);
	pad(lens[3], ' ', fd);
	return (lens[0] + lens[1] + lens[2] + lens[3]);
}
