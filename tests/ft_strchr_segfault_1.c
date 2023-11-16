/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_segfault_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:56:03 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/16 13:42:32 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	char *s = 0;
	printf("%p\n", ft_strchr(s, 0));
	printf("ERROR! SEGFAULT WAS EXPECTED!\n");
	return (1);
}
