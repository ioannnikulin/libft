/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:46:27 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/24 18:29:05 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux_printf.h"

int	put_s(char **c, va_list *argv, int fd, t_params params)
{
	size_t	l;
	char	*s;

	(*c) ++;
	s = va_arg(argv, char *);
	l = ft_strlen(s);
	if (params.precision && params.precision < l)
		l = params.precision;
	write(fd, s, l);
	return (l);
}
