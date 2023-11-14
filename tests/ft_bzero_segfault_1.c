/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_segfault_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:03 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/14 19:32:41 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	char *s = 0;
//	ft_bzero(s, 0);
	bzero(s, (1));
	printf("ERROR! SEGFAULT WAS EXPECTED!\n");
	return (1);
}
/*void	ft_bzero_test(void)
{
	size_t t[SZ] = {3, 1, 0};
	for (int i = 0; i < SZ; i ++)
	{
		char * custom_src = ft_bzero_test_prep(t[i]);
		char * std_src = ft_bzero_test_prep(t[i]);
		ft_bzero(custom_src, t[i]);
		bzero(std_src, t[i]);
		for (size_t j = 0; j < t[i] + 2; j ++)
			assert(custom_src[j] == std_src[j]);
		free(std_src);
		free(custom_src);
	}
	
	   char * custom_res = 0;
	ft_bzero(custom_res, 5);
	char * std_res = 0;
	bzero(std_res, 5); // segfault in system bzero, so no
	if (custom_res != std_res)
		for (int j = 0; j < 7; j ++)
			assert(custom_res[j] == std_res[j]);
	
}*/
