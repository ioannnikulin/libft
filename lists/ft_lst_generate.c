/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_generate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/22 20:45:57 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	make_worm(t_list **root, char *texts[])
{
	int		idx;
	t_list	*curnode;

	*root = ft_lstnew(ft_strdup(texts[0]));
	if (!*root)
		return (-1);
	idx = 1;
	curnode = *root;
	while (texts[idx])
	{
		curnode->next = ft_lstnew(ft_strdup(texts[idx]));
		if (!curnode->next)
		{
			ft_lstclear(root, free);
			return (-1);
		}
		idx ++;
		curnode = curnode->next;
	}
	return (idx);
}

t_list	*ft_lst_generate(char *texts[], int end_to)
{
	t_list	*root;
	t_list	*curnode;
	t_list	*tail;
	int		idx;

	if (!texts || !texts[0])
		return (0);
	idx = make_worm(&root, texts);
	if (idx == -1)
		return (0);
	if (end_to >= idx)
	{
		ft_lstclear(&root, free);
		return (0);
	}
	if (end_to == -1)
		return (root);
	tail = ft_lstlast(root);
	idx = -1;
	curnode = root;
	while (++ idx < end_to)
		curnode = curnode->next;
	tail->next = curnode;
	return (root);
}
