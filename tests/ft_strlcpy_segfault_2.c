/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_segfault_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:03 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/15 18:24:15 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	char *s = calloc(1, 1);
	if (!s)
	{
		printf("ERROR: failed to allocate memory for testing. Result unknown.\n");
		return (1);
	}
	char *d = 0;
	strlcpy(d, s, (0));
	strlcpy(d, s, (1));
	printf("ERROR! SEGFAULT WAS EXPECTED!\n");
	return (1);
}
