/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:31 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/14 19:02:30 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <stdio.h>

int	main(void)
{
	ft_isalpha_test();
	printf("isalpha ok\n");
	ft_isdigit_test();
	printf("isdigit ok\n");
	ft_isalnum_test();
	printf("isalnum ok\n");
	ft_isascii_test();
	printf("isascii ok\n");
	ft_isprint_test();
	printf("isprint ok\n");
	ft_strlen_test();
	printf("strlen ok\n");
	ft_memset_test();
	printf("memset ok\n");
	ft_bzero_test();
	printf("bzero ok\n");
	ft_memcpy_test();
	printf("memcpy ok\n");
	ft_memmove_test();
	printf("memmove ok\n");
	printf("All tests passed successfully!\n");
	return (0);
}
