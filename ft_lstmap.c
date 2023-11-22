/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/22 20:45:01 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	connect_tail(t_list *res, t_list *res_tail, t_list *orig)
{
	t_list	*orig_loop_to;

	orig_loop_to = ft_lstlast(orig)->next;
	if (!orig_loop_to)
		return ;
	while (orig != orig_loop_to)
	{
		res = res->next;
		orig = orig->next;
	}
	res_tail->next = res;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list	*res;
	t_list	*iter_res;
	t_list	*iter_orig;
	t_list	*nnode;
	int		lstlen;

	lstlen = ft_lstsize(lst);
	if (!lstlen)
		return (0);
	res = 0;
	iter_orig = lst;
	iter_res = res;
	while (lstlen --)
	{
		nnode = ft_lstnew(f(iter_orig->content));
		if (!nnode)
		{
			ft_lstclear(&res, del);
			return (0);
		}
		if (res)
			iter_res->next = nnode;
		else
			res = nnode;
		iter_orig = iter_orig->next;
		iter_res = nnode;
	}
	connect_tail(res, ft_lstlast(res), lst);
	return (res);
}
