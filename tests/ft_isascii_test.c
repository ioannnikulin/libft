/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:20 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/14 16:25:30 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_isascii_test(void)
{
	assert(ft_isascii('/') == 1);
	assert(ft_isascii(':') == 1);
	assert(ft_isascii('0') == 1);
	assert(ft_isascii('1') == 1);
	assert(ft_isascii('9') == 1);
	assert(ft_isascii('a') == 1);
	assert(ft_isascii('z') == 1);
	assert(ft_isascii('A') == 1);
	assert(ft_isascii('Z') == 1);
	assert(ft_isascii(2000000000) == 0);
	assert(ft_isascii(-2147483648) == 0);
	assert(ft_isascii(2147483647) == 0);
	assert(ft_isascii(-1) == 0);
	assert(ft_isascii(128) == 0);
	assert(ft_isascii('\0') == 1);
	assert(ft_isascii('\n') == 1);
	assert(ft_isascii('\t') == 1);
	assert(ft_isascii('!') == 1);
	assert(ft_isascii('@') == 1);
	assert(ft_isascii('[') == 1);
	assert(ft_isascii('`') == 1);
	assert(ft_isascii('{') == 1);
}
