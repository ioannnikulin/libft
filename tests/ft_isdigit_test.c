/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:12 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/14 16:21:48 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_isdigit_test(void)
{
	assert(ft_isdigit('/') == 0);
	assert(ft_isdigit(':') == 0);
	assert(ft_isdigit('0') == 1);
	assert(ft_isdigit('1') == 1);
	assert(ft_isdigit('9') == 1);
	assert(ft_isdigit('a') == 0);
	assert(ft_isdigit('z') == 0);
	assert(ft_isdigit('A') == 0);
	assert(ft_isdigit('Z') == 0);
	assert(ft_isdigit(128) == 0);
	assert(ft_isdigit(2000000000) == 0);
	assert(ft_isdigit(-2147483648) == 0);
	assert(ft_isdigit(2147483647) == 0);
	assert(ft_isdigit(-1) == 0);
	assert(ft_isdigit('\0') == 0);
	assert(ft_isdigit('\n') == 0);
	assert(ft_isdigit('\t') == 0);
	assert(ft_isdigit('!') == 0);
	assert(ft_isdigit('@') == 0);
	assert(ft_isdigit('[') == 0);
	assert(ft_isdigit('`') == 0);
	assert(ft_isdigit('{') == 0);
}
