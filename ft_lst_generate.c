/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_generate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2023/11/21 19:05:10 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	clear(void *s)
{
	char	*c;

	c = (char*)s;
	free(s);//c);
}

t_list	*ft_lst_generate(char *texts[], int end_to)
{
	t_list	*root;
	t_list	*curnode;
	t_list	*tail;
	int	idx;

	if (!texts || !texts[0])
		return (0);
	root = ft_lstnew(ft_strdup(texts[0]));
	if (!root)
		return (0);
	idx = 1;
	curnode = root;
	while (texts[idx])
	{
		curnode->next = ft_lstnew(ft_strdup(texts[idx]));
		if (!curnode->next)
		{
			ft_lstclear(&root, clear);
			return (0);
		}
		idx ++;
		curnode = curnode->next;
	}
	if (end_to >= idx)
	{
		ft_lstclear(&root, clear);
		return (0);
	}
	if (end_to == -1)
		return (root);
	tail = curnode;
	idx = -1;
	curnode = root;
	while (++ idx < end_to)
		curnode = curnode->next;
	tail->next = curnode;
	return (root);
}
