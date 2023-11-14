/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_segfault_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:03 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/14 20:54:21 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	char *s = calloc(1, 1);
	if (s == NULL)
	{
		printf("ERROR: couldn't allocate memory for testing. Result unkown.\n");
		return (1);
	}
	char *d = 0;
	ft_memmove(d, s, (1));
	printf("ERROR! SEGFAULT WAS EXPECTED!\n");
	return (1);
}
