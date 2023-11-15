/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_segfault_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:03 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/15 13:03:35 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	char *s = 0;
	ft_bzero(s, (1));
	printf("ERROR! SEGFAULT WAS EXPECTED!\n");
	return (1);
}
