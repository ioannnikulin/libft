/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:46:27 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/28 19:00:36 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_printf.h"
#define MX 65

int	put_x(char **c, va_list *argv, int fd, t_params params)
{
	size_t	pure_len;
	size_t	res_len;
	char	s[MX];
	int		p;

	p = va_arg(*argv, int);
	params.capital_hex = 0;
	params.sign_mandatory = 0;
	params.space_before_positive = 0;
	if (**c == 'X')
		params.capital_hex = 1;
	(*c)++;
	if (!p)
		params.hex_prefix = 0;
	if (params.capital_hex)
		pure_len = ft_ulltoa_base(p, "0123456789ABCDEF", s);
	else
		pure_len = ft_ulltoa_base(p, "0123456789abcdef", s);
	if (!p && !params.precision)
		pure_len = 0;
	res_len = pad_n_put(s, pure_len, fd, params);
	return (res_len);
}
