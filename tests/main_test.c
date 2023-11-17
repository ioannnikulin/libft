/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:31 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/17 14:27:44 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <stdio.h>

int	bad_alloc(int ret)
{
	printf("ERROR: couldn't allocate memory for testing. Results unknown.\n");
	return (ret);
}

int	segfault_expected(int ret)
{
	printf("ERROR: SEGFAULT EXPECTED!\n");
	return (ret);
}

int	main(void)
{
	printf("isalpha in testing\n");
	ft_isalpha_test();
	printf("isdigit in testing\n");
	ft_isdigit_test();
	printf("isalnum in testing\n");
	ft_isalnum_test();
	printf("isascii in testing\n");
	ft_isascii_test();
	printf("isprint in testing\n");
	ft_isprint_test();
	printf("strlen in testing\n");
	ft_strlen_test();
	printf("memset in testing\n");
	ft_memset_test();
	printf("bzero in testing\n");
	ft_bzero_test();
	printf("memcpy in testing\n");
	ft_memcpy_test();
	printf("memmove in testing\n");
	ft_memmove_test();
	printf("strlcpy in testing\n");
	ft_strlcpy_test();
	printf("strlcat in testing\n");
	ft_strlcat_test();
	printf("toupper in testing\n");
	ft_toupper_test();
	printf("tolower in testing\n");
	ft_tolower_test();
	printf("strchr in testing\n");
	ft_strchr_test();
	printf("strrchr in testing\n");
	ft_strrchr_test();
	printf("strncmp in testing\n");
	ft_strncmp_test();
	printf("memchr in testing\n");
	ft_memchr_test();
	printf("strnstr in testing\n");
	ft_strnstr_test();
	printf("All tests passed successfully!\n");
	return (0);
}
