/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:46:27 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/28 19:49:16 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_printf.h"
#define MX 65

int	put_p(char **c, va_list *argv, int fd, t_params params)
{
	size_t				pure_len;
	size_t				res_len;
	char				s[MX];
	unsigned long long	p;

	(*c)++;
	p = va_arg(*argv, unsigned long long);
	params.hex_prefix = 1;
	params.min_width = 0;
	pure_len = ft_ulltoa_base(p, "0123456789abcdef", s);
	res_len = pad_n_put(s, pure_len, fd, params);
	return (res_len);
}