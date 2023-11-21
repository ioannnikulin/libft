/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/21 16:48:45 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*fast;
	t_list	*slow;
	int		len;

	if (lst == 0)
		return (0);
	if (lst->next == 0)
		return (1);
	if (lst->next->next == 0)
		return (2);
	fast = lst->next->next;
	slow = lst->next;
	len = 2;
	while (fast != slow && fast != 0 && fast->next != 0)
	{
		fast = fast->next->next;
		slow = slow->next;
		len += 2;
	}
	if (fast == 0)
		return (len);
	if (fast->next == 0)
		return (len + 1);
	fast = lst;
	len /= 2;
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
		len ++;
	}
	return (len);
}
