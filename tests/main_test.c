/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:31 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/18 14:54:16 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <stdio.h>

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
	printf("atoi in testing\n");
	ft_atoi_test();
	printf("strdup in testing\n");
	ft_strdup_test();
	printf("substr in testing\n");
	ft_substr_test();
	printf("strjoin in testing\n");
	ft_strjoin_test();
	printf("strtrim in testing\n");
	ft_strtrim_test();
	printf("split in testing\n");
	ft_split_test();
	printf("itoa in testing\n");
	ft_itoa_test();
	printf("strmapi in testing\n");
	ft_strmapi_test();
	printf("striteri in testing\n");
	ft_striteri_test();
	printf("All tests passed successfully!\n");
	return (0);
}
