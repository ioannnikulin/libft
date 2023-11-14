/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:43 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/14 16:17:39 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	ft_isalpha_test(void)
{
	assert(ft_isalpha('/') == 0);
	assert(ft_isalpha(':') == 0);
	assert(ft_isalpha('0') == 0);
	assert(ft_isalpha('1') == 0);
	assert(ft_isalpha('9') == 0);
	assert(ft_isalpha('a') == 1);
	assert(ft_isalpha('z') == 1);
	assert(ft_isalpha('A') == 1);
	assert(ft_isalpha('Z') == 1);
	assert(ft_isalnum(2000000000) == 0);
	assert(ft_isalnum(-2147483648) == 0);
	assert(ft_isalnum(2147483647) == 0);
	assert(ft_isalnum(-1) == 0);
	assert(ft_isalnum(128) == 0);
	assert(ft_isalpha('\0') == 0);
	assert(ft_isalpha('\n') == 0);
	assert(ft_isalpha('\t') == 0);
	assert(ft_isalpha('!') == 0);
	assert(ft_isalpha('@') == 0);
	assert(ft_isalpha('[') == 0);
	assert(ft_isalpha('`') == 0);
	assert(ft_isalpha('{') == 0);
}
