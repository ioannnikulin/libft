/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:01 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/14 16:24:21 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_isalnum_test(void)
{
	assert(ft_isalnum('/') == 0);
	assert(ft_isalnum(':') == 0);
	assert(ft_isalnum('0') == 1);
	assert(ft_isalnum('1') == 1);
	assert(ft_isalnum('9') == 1);
	assert(ft_isalnum('a') == 1);
	assert(ft_isalnum('z') == 1);
	assert(ft_isalnum('A') == 1);
	assert(ft_isalnum('Z') == 1);
	assert(ft_isalnum(2000000000) == 0);
	assert(ft_isalnum(-2147483648) == 0);
	assert(ft_isalnum(2147483647) == 0);
	assert(ft_isalnum(-1) == 0);
	assert(ft_isalnum(128) == 0);
	assert(ft_isalnum('\0') == 0);
	assert(ft_isalnum('\n') == 0);
	assert(ft_isalnum('\t') == 0);
	assert(ft_isalnum('!') == 0);
	assert(ft_isalnum('@') == 0);
	assert(ft_isalnum('[') == 0);
	assert(ft_isalnum('`') == 0);
	assert(ft_isalnum('{') == 0);
}
