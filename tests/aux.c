/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:31 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/17 14:30:52 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
