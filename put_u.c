/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:46:27 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/29 13:23:56 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_printf.h"
#define MX 65

int	put_u(char **c, va_list *argv, int fd, t_params params)
{
	size_t			pure_len;
	size_t			res_len;
	char			s[MX];
	unsigned int	p;

	(*c)++;
	params.hex_prefix = 0;
	params.sign_mandatory = 0;
	params.space_before_positive = 0;
	p = va_arg(*argv, unsigned int);
	pure_len = ft_lltoa_base(p, "0123456789", s);
	res_len = pad_n_put(s, pure_len, fd, params);
	return (res_len);
}
