/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_segfault_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:03 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/14 20:39:59 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	char *d = 0;
	char *s = calloc(1, 1);
	if (s == NULL)
	{
		printf("ERROR: couldn't allocate memory for testing, result unknown.\n")
		return (1);
	}
	ft_memcpy(d, s, (1));
	printf("ERROR! SEGFAULT WAS EXPECTED!\n");
	free(s);
	return (1);
}
