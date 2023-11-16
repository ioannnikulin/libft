/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp_segfault_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:03 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/16 17:48:13 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	char *s = 0;
	char *d = calloc(10, 1);
	if (!d)
	{
		printf("ERROR: couldn't allocate memory for testing. Results unknown.\n");
		return (1);
	}
	ft_memcmp(d, s, 1);
	printf("ERROR! SEGFAULT WAS EXPECTED!\n");
	return (1);
}
