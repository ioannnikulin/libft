/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/22 17:13:14 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_lst_print(t_list *lst)
{
	int	lstlen;

	lstlen = ft_lstsize(lst);
	while (lstlen --)
	{
		printf("%p [%s] -> ", lst, (char *)lst->content);
		lst = lst->next;
	}
	printf("%p\n", lst);
	return (lstlen);
}
