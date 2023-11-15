/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_segfault_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:03 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/15 12:51:10 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	char *s = 0;
	char *d = calloc(1, 1);
	if (d == NULL)
	{
		printf("ERROR: couldn't allocate memory for testing, result unknown.\n");
		return (1);
	}
	ft_memcpy(d, s, (1));
	printf("ERROR! SEGFAULT WAS EXPECTED!\n");
	free(d);
	return (1);
}
