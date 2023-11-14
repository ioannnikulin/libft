/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:53 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/14 16:27:39 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_isprint_test(void)
{
	assert(ft_isprint('/') == 1);
	assert(ft_isprint(':') == 1);
	assert(ft_isprint('0') == 1);
	assert(ft_isprint('1') == 1);
	assert(ft_isprint('9') == 1);
	assert(ft_isprint('a') == 1);
	assert(ft_isprint('z') == 1);
	assert(ft_isprint('A') == 1);
	assert(ft_isprint('Z') == 1);
	assert(ft_isprint(2000000000) == 0);
	assert(ft_isprint(-2147483648) == 0);
	assert(ft_isprint(2147483647) == 0);
	assert(ft_isprint(-1) == 0);
	assert(ft_isprint(128) == 0);
	assert(ft_isprint('\0') == 0);
	assert(ft_isprint('\n') == 0);
	assert(ft_isprint('\t') == 0);
	assert(ft_isprint('!') == 1);
	assert(ft_isprint('@') == 1);
	assert(ft_isprint('[') == 1);
	assert(ft_isprint('`') == 1);
	assert(ft_isprint('{') == 1);
	assert(ft_isprint(' ') == 1);
	assert(ft_isprint(31) == 0);
}
